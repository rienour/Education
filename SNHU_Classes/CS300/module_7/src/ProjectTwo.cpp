//============================================================================
// Name        : ProjectTwo.cpp
// Developer   : Riley Eichenour
// Description : SNHU Project Two - ABCU Course Processor
//============================================================================

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

enum MenuOption {
  LoadFile = 1,
  PrintCourseList = 2,
  FindCourse = 3,
  Exit = 9,
};

/**
 * This error was provided as part of the CS300 CSV parser files
 *
 * All credit goes to SNHU for logic
 */
class Error : public std::runtime_error {
  public:
    Error(const std::string& msg)
        : std::runtime_error(std::string("Parser : ").append(msg)) {}
};

//==============================================================================
//
// Forward Declarations
//
//==============================================================================

struct Course {
    string identifier;
    string name;
    vector<string> prerequisites;
    void print() {
      cout << "Course ID: " << this->identifier << endl
           << "Course Name: " << this->name << endl
           << "Course Prerequisites: ";

      // Print prerequisites if they exist
      if (!this->prerequisites.empty()) {
        vector<string>::iterator it;
        for (it = this->prerequisites.begin();
             it != this->prerequisites.end() - 1; it++) {
          cout << *it << ", ";
        }
        cout << this->prerequisites.back() << endl << endl;
      } else {
        cout << "None" << endl;
      }
    }
    Course() {};
    Course(const string& identifier, const string& name) {
      this->identifier = identifier;
      this->name = name;
    };
};

class Row {
  public:
    Row();
    ~Row();
    void push(string);
    unsigned int size();
    const string& operator[](unsigned int) const;

  private:
    vector<string> content;
};

class Parser {
  public:
    Parser(const string&);
    ~Parser();
    unsigned int rowCount() const;
    Row& operator[](unsigned int) const;

  private:
    vector<Row*> rows;
    vector<string> fileData;
    void parseContent();
};

class CourseTree {
  private:
    struct Node {
        Node* left;
        Node* right;
        Course course;
        Node(Course& course) {
          this->course = course;
          this->left = nullptr;
          this->right = nullptr;
        };
    };
    Node* root;
    void destroyTree(Node*);
    void addNode(Node*, Course);
    void inOrderPrint(Node*);

  public:
    CourseTree();
    ~CourseTree();
    Course search(string);
    void insert(Course);
    void printAllCourses();
    void validatePrerequisites();
};

void loadCourses(const string&, CourseTree*);

//==============================================================================
//
//  Row Class
//
//  This class is adapted from the CS300 provided CSV parser files
//
//==============================================================================
/**
 * Default Constructor
 */
Row::Row() : content() {}

/**
 * Destructor
 */
Row::~Row() {};

/**
 * This function handles appending a new item to the row content
 */
void Row::push(string item) { this->content.push_back(item); }

/**
 * This function handles getting the count of items in the content
 *
 * @returns unsigned integer indicating the count of items
 */
unsigned int Row::size() { return this->content.size(); }

/**
 * This operator handles exposing the row content via the index operator
 */
const string& Row::operator[](unsigned int index) const {
  if (index < this->content.size()) {
    return this->content[index];
  }
  throw Error("[ERROR] - Row content index out of bounds.");
}

//==============================================================================
//
// End Row class definition
//
//==============================================================================

//==============================================================================
//
//  Parser Class
//
//  This class is adapted from the CS300 provided CSV parser files
//
//==============================================================================
/**
 * Default Constructor
 *
 * @param fileName Name of the file to read the input data from
 */
Parser::Parser(const string& fileName) {
  string curLine;

  // Attempt to open the file
  ifstream infile(fileName.c_str());

  if (infile.is_open()) {
    cout << "[INFO] - Course Input file " << fileName << " opened successfully"
         << endl;

    // Read the file while there are lines to read
    while (infile.good()) {
      getline(infile, curLine);

      // Remove carriage returns if they exist
      curLine.erase(remove_if(curLine.begin(), curLine.end(), ::iscntrl),
                    curLine.end());

      // Only add a line if there is meaningful content
      if (!curLine.empty()) {
        fileData.push_back(curLine);
      }
    }

    // Close file after reading data into memory
    infile.close();

    if (this->fileData.empty()) {
      throw Error(string(("[ERROR] - No data to read from ")).append(fileName));
    }

    this->parseContent();
  } else {
    throw Error(string(("[ERROR] - Unable to open file ")).append(fileName));
  }
}

/**
 * Destructor
 */
Parser::~Parser() {
  vector<Row*>::iterator it;
  for (it = this->rows.begin(); it != this->rows.end(); it++) {
    delete *it;
  }
}

/**
 * This function handles returning the number of rows in the parsed data
 */
unsigned int Parser::rowCount() const { return this->fileData.size(); }

/**
 * This function handles processing the loaded raw string content into a row
 */
void Parser::parseContent() {
  // Iterate through each of the loaded rows
  vector<string>::iterator it;
  for (it = fileData.begin(); it != fileData.end(); it++) {
    bool escaped = false;
    int tokenStart = 0;
    unsigned int i = 0;
    Row* row = new Row();
    string newToken = "";

    // Iterate through the string to tokenize it
    for (i = 0; i < it->length(); i++) {
      if (it->at(i) == '"') {
        // Toggle the escape flag when an escape character is seen
        escaped = !escaped;
      } else if (it->at(i) == ',' && !escaped) {
        // Add the token to the row data
        newToken = it->substr(tokenStart, i - tokenStart);
        if (!newToken.empty()) {
          row->push(newToken);
        }
        tokenStart = i + 1;
      }
    }
    newToken = it->substr(tokenStart, it->length() - tokenStart);
    if (!newToken.empty()) {
      row->push(newToken);
    }

    this->rows.push_back(row);
  }
}

/**
 * This operator handles exposing the rows via the index operator
 */
Row& Parser::operator[](unsigned int index) const {
  if (index < this->rows.size()) {
    return *this->rows[index];
  }
  throw Error("[ERROR] - Row index out of bounds.");
}

//==============================================================================
//
// End Parser class definition
//
//==============================================================================

//==============================================================================
//
// CourseTree class definition
//
//==============================================================================

/**
 * Default Constructor
 */
CourseTree::CourseTree() { this->root = nullptr; }

/**
 * Destructor
 */
CourseTree::~CourseTree() { destroyTree(this->root); }

/**
 * This helper function handles deleting a tree given the root node and
 * recursively handles deleting the children through post order traversal.
 *
 * Original Implementation from CS300 - Module 6 Submission by Riley Eichenour
 *
 * @param root Node for the root of the tree to delete
 */
void CourseTree::destroyTree(Node* root) {
  if (root != nullptr) {
    // Traverse the left subtree
    this->destroyTree(root->left);

    // Traverse the right subtree
    this->destroyTree(root->right);

    // Delete the tree root
    delete root;
  }
}
/**
 * Search for a course given the identifier
 *
 * Original Implementation from CS300 - Module 6 Submission by Riley Eichenour
 *
 * @param courseIdentifier string representing the target course
 * @return Course in the tree, or default Course if it is not found
 */
Course CourseTree::search(string courseIdentifier) {
  // Create node to track the current check node
  Node* curNode = this->root;

  while (curNode != nullptr) {
    // The current node has the target bid
    if (curNode->course.identifier == courseIdentifier) {
      return curNode->course;
    }
    // Traverse left subtree if current bid is too large
    else if (curNode->course.identifier > courseIdentifier) {
      curNode = curNode->left;
    }
    // Traverse left subtree if current bid is too small
    else {
      curNode = curNode->right;
    }
  }

  Course course;
  return course;
}

/**
 * Add a course to some node (recursive)
 *
 * Original Implementation from CS300 - Module 6 Submission by Riley Eichenour
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void CourseTree::addNode(Node* node, Course course) {
  // The new course is less than the current node course
  if (node->course.identifier > course.identifier) {
    // There is no left child
    if (node->left == nullptr) {
      node->left = new Node(course);
    }
    // Traverse down left subtree
    else {
      addNode(node->left, course);
    }
  }
  // The new course is greater or equal to the current node course
  else {
    // There is no right child
    if (node->right == nullptr) {
      node->right = new Node(course);
    }
    // Traverse down right subtree
    else {
      addNode(node->right, course);
    }
  }
}

/**
 * Insert a course
 *
 * Original Implementation from CS300 - Module 6 Submission by Riley Eichenour
 *
 * @param course Course value that the node will hold
 */
void CourseTree::insert(Course course) {
  // Create a new node with the bid information
  Node* newNode = new Node(course);

  // Set the root if the tree is empty
  if (this->root == nullptr) {
    this->root = newNode;
  }
  // Traverse the tree to find the insertion position
  else {
    addNode(this->root, course);
  }
}

/**
 * Print all courses in the tree in order
 *
 * Original Implementation from CS300 - Module 6 Submission by Riley Eichenour
 *
 * @param Node node to traverse from
 */
void CourseTree::inOrderPrint(Node* node) {
  if (node == nullptr) {
    return;
  }

  inOrderPrint(node->left);
  node->course.print();
  inOrderPrint(node->right);
}

/**
 * Wrapper method to handle printing the courses
 *
 * Original Implementation from CS300 - Module 6 Submission by Riley
 * Eichenour
 */
void CourseTree::printAllCourses() { this->inOrderPrint(this->root); }

/**
 * Wrapper method to handle printing the courses
 *
 * Original Implementation from CS300 - Module 6 Submission by Riley Eichenour
 */
void CourseTree::validatePrerequisites() { this->inOrderPrint(this->root); }

//==============================================================================
//
// End CourseTree class definition
//
//==============================================================================

/**
 * This function handles formatting and printing the menu options to the user
 */
void displayMenu() {
  cout << "Welcome to the ABCU course planner" << endl << endl;
  printf("\t%d: Load course Data\n", MenuOption::LoadFile);
  printf("\t%d: Print Course List\n", MenuOption::PrintCourseList);
  printf("\t%d: Find Course\n", MenuOption::FindCourse);
  printf("\t%d: Exit Course Processor\n\n", MenuOption::Exit);
  cout << "Enter an option: ";
}

/**
 * This function handles loading the courses from the input file and into the
 * in-memory data structure.
 *
 * @param filePath string representing the path of the CSV file to load
 * @param courses Data structure to contain the loaded courses in memory
 */
void loadCourses(const string& filePath, CourseTree* courses) {
  cout << "[INFO] - Loading courses from " << filePath << endl;

  Parser file = Parser(filePath);
  try {
    Course curCourse;
    for (unsigned int i = 0; i < file.rowCount(); i++) {
      // Get the number of tokenized items in the row
      unsigned int rowItemCount = file[i].size();

      if (rowItemCount < 2) {
        // Notify the user there is a malformed row in the file
        cerr << "[ERROR] - Malformed row at " << i << " in " << filePath
             << endl;

        // Exit program
        exit(EXIT_FAILURE);
      }

      // Set the course attributes
      curCourse = Course(file[i][0], file[i][1]);

      // Check if there is a prerequisites list
      if (rowItemCount > 2) {
        for (unsigned int j = 2; j < rowItemCount; j++) {
          if (file[i][j] == "") {
            cout << "[WARN] - Empty prerequisite found on row " << i
                 << ". Omitting empty prerequisite." << endl;
          } else {
            curCourse.prerequisites.push_back(file[i][j]);
          }
        }
      }

      courses->insert(curCourse);
    }
  } catch (Error& e) {
    cerr << e.what() << endl;
  }
}

/*
 * Main to Run the ABCU Course Processor application
 */
int main(int argc, char* argv[]) {
  // Set user choice to invalid menu entry option
  int userChoice = -1;
  string userInput = "";
  Course searchCourse;

  CourseTree* courses = new CourseTree();

  while (userChoice != MenuOption::Exit) {
    // Print the menu with options for user reference
    displayMenu();

    // Attempt to get input from user
    if (cin >> userChoice) {
      switch (userChoice) {
        case MenuOption::LoadFile:
          cout << "Enter file path to load courses from: ";
          // Read the file name, including spaces and omit whitespace in cin
          getline(cin >> ws, userInput);
          loadCourses(userInput, courses);
          // Clear the userInput string
          userInput = "";
          break;

        case MenuOption::PrintCourseList:
          courses->printAllCourses();
          break;

        case MenuOption::FindCourse:
          cout << "Enter course id to search for: ";
          getline(cin >> ws, userInput);
          searchCourse = courses->search(userInput);
          // Clear the userInput string
          userInput = "";
          if (!searchCourse.identifier.empty()) {
            searchCourse.print();
          } else {
            cout << "Course not found." << endl;
          }
          break;

        case MenuOption::Exit:
          cout << "Course processer exit signal received. Stopping "
                  "application..."
               << endl;
          break;

        default:
          cout << "\a[WARN] - Invalid option " << userChoice
               << " input. Please select a valid menu option." << endl;
      }
    } else {
      // Print error to user if they enter an invalid data type
      cerr << "\a[ERROR] - Invalid input type received. Please enter a "
              "positive integer."
           << endl;

      // Clear the invalid input
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  return 0;
}
