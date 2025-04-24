/**
 * Author Riley Eichenour
 * Assignment: Project Three
 * Purpose: The purpose of this program is to demonstrate student competency to
 * design class and functional programs that comply with industry regulations.
 * This will be demonstrated through an example grocery tracker utility.
 */

#include "GroceryTracker.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

/*
 * This function prints a character a count number of times.
 *
 * @param count The number of times to print the character
 * @param repeatChar The character to be repeated count times
 *
 * Adapted from `printStars` provided by Richard Foster, SNHU, CS210
 * Adaptation from Riley Eichenour, CS210, Project One Submission
 *
 * @usage
 * printCharNTimes('*', 1); // Standard output will show *
 * printCharNTimes('|', 5); // Standard output will show |||||
 */
void printCharNTimes(char repeatChar, unsigned short count) {
  cout << string(count, repeatChar);
} // printCharacter

/*
 * This function checks if the provided value is within a provided range,
 * inclusive of the edges of the range.
 *
 * Original Code from Riley Eichenour, CS210, Project One submission
 *
 * @param checkValue Provided value to determine whether it is within the range
 * inclusively
 * @param min The minimum value allowed within the range
 * @param max The maximum value allowed within the range
 *
 * @return Boolean indicating whether the value is inclusively within the range
 */
bool isInRangeInclusive(short checkValue, short min, short max) {
  return (checkValue >= min) && (checkValue <= max);
} // isInRangeInclusive

/*
 * This function displays a message to the user asking them to enter a short. It
 * ensures the input is a short and that the value entered is within a specified
 * range. On invalid input the user will be alerted and prompted with an error
 * message.
 *
 * Originally Adapted from `getInteger` provided by Richard Foster, SNHU, CS210
 * Additionally adaptation performed from Riley Eichenour, CS210 Project One
 * submission
 *
 * @param prompt Messaged to display to the user prompting input. Between
 * statement will be appended to the prompt.
 * @param min The lowest short value the user is allowed to enter
 * @param max The highest short value the user is allowed to enter
 *
 * @return The short provided with the user that is within the range
 */
short getShort(string prompt, short min, short max) {
  // Initialize variable to store user input
  short userChoice = 0;

  // Prompt user for input until an accepted input is provided
  do {
    cout << prompt << "(" << min << " - " << max << "): ";
    cin >> userChoice;

    // Check if the user entered a valid value
    if (cin.fail()) {
      // Alert and print an error message to the user
      cerr << "\aA valid short must be entered. Please enter a new value."
           << endl;

      // Clear the error from cin to allow continued input
      cin.clear();
    } else if (!isInRangeInclusive(userChoice, min, max)) {
      // Notify the user their value is not in the range
      cout << "\aThe value must be between " << min << " and " << max
           << " inclusive." << endl;
    }

    // Read to a new line to prepare for next prompt
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (isInRangeInclusive(userChoice, min, max) == false);

  return userChoice;
} // getShort

/*
 * This function takes the provided user menu entry and dispatches the
 * associated change with the menu entry.
 *
 * @param menuEntry The selection by the user for a selection
 */
void dispatchMenuEntry(short menuEntry, const GrocerTracker &inputTracker) {
  switch (menuEntry) {
  case 1: // Find Item Frequency
    inputTracker.PrintItemFrequency();
    break;
  case 2: // Print All Items Frequencies
    inputTracker.PrintItemFrequencies();
    break;
  case 3: // Print Items Histogram
    inputTracker.PrintItemHistogram();
    break;
  case 4: // Exit
    cout << "Application Exit request received. Exiting program..." << endl;
    break;
  default: // Default case to notify of invalid menu entry
    cerr << "\a[ERROR] - Invalid Selection. Please enter valid menu entry"
         << endl;
  } // switch
} // dispatchMenuEntry

/*
 * This function handles printing the menu for the Grocer Tracking Program.
 *
 * Supported options include:
 *  1. Find Item Frequency
 *  2. Print All Items Frequencies
 *  3. Print All Items Histogram
 *  4. Exit program
 */
void printMenu() {
  // Print Menu header
  printCharNTimes('-', 32);
  cout << endl;
  cout << "Grocer Tracking Program" << endl;
  printCharNTimes('-', 32);
  cout << endl;

  // Print supported menu items
  cout << "1 - Find Item Frequency" << endl;
  cout << "2 - Print All Items Frequencies" << endl;
  cout << "3 - Print All Items Histogram" << endl;
  cout << "4 - Exit program" << endl;
  printCharNTimes('-', 32);
  cout << endl;
} // printMenu

/**
 * This function handles checking an input file stream to verify that it opened
 * successfully. If the file is not open, then an error message is displayed and
 * exit is performed.
 *
 * @param fileStream Reference to the input file stream to open
 * @param fileName Text representation for the fileName, which should match the
 * file utilized for the fstream for user reference
 */
void openInputFile(ifstream &fileStream, const string fileName) {
  cout << "[INFO] - Attempting to open input file " << fileName << "..."
       << endl;

  fileStream.open(fileName);
  cout << "[INFO] - Validating input " << fileName << " is open..." << endl;
  if (!fileStream.is_open()) {
    // Notify user there was an error and return error exit code
    cerr << "[ERROR] - Unable to open input file with name " << fileName
         << endl;
    exit(EXIT_FAILURE);
  } // file stream open check
} // openInputFile

/**
 * This function handles checking an output file stream to verify that it opened
 * successfully. If the file is not open, then an error message is displayed and
 * exit is performed.
 *
 * @param fileStream Reference to the output file stream to open
 * @param fileName Text representation for the fileName, which should match the
 * file utilized for the fstream for user reference
 */
void openOutputFile(ofstream &fileStream, const string fileName) {
  cout << "[INFO] - Attempting to open output file " << fileName << "..."
       << endl;

  fileStream.open(fileName);
  cout << "[INFO] - Validating output " << fileName << " is open..." << endl;
  if (!fileStream.is_open()) {
    // Notify user there was an error and return error exit code
    cerr << "[ERROR] - Unable to open output file with name " << fileName
         << endl;
    exit(EXIT_FAILURE);
  } // file stream open check
} // openOutputFile

/*
 * Grocer Tracker Class Definition
 */
GrocerTracker::GrocerTracker(map<string, int> initialItems) {
  this->GrocerItems = initialItems;

  // Iterate through the items to find the max name length
  int maxNameLength =
      0; // Temp variable to store highest variable length seen so far
  int currItemLength = 0;
  for (const auto &value : initialItems) {
    currItemLength = value.first.length();
    if (currItemLength > maxNameLength) {
      maxNameLength = currItemLength;
    } // if length check
  } // for
  this->MaxNameLength = maxNameLength;
};

/*
 * This function formats the current map stored for the data with each key and
 * value pair separated by a space in the output stream followed by a newline
 */
void GrocerTracker::WriteOutputData(ofstream &outData) const {
  for (const auto &[key, value] : this->GrocerItems) {
    outData << key << " " << value << endl;
  }
}

/*
 * This function reads the input data from the input stream. Any values that
 * cannot be read are omitted from the output data and the user is warned
 * about the omission of data.
 *
 * @param inData Input stream utilized to read for Grocer Tracker input
 */
void GrocerTracker::ReadInputData(ifstream &inData) {
  string item = "";
  while (getline(inData, item)) {
    if (cin.fail()) {
      // Notify the user there was erroneous data and it will be omitted
      cerr << "[ERROR] - Unable to read data for item: " << item
           << ". Omitting from input data" << endl;

      // Clear input stream and continue without performing additional checks
      inData.clear();
      continue;
    }

    // Check if the item exists in the map, and add it if not
    if (this->GrocerItems.find(item) != this->GrocerItems.end()) {
      this->GrocerItems[item]++;
    } else {
      // Check if the read item has a greater name length than what was seen
      // so far
      if (item.length() > this->MaxNameLength) {
        this->MaxNameLength = item.length();
      }

      // Add need item into the list with the initial count of 1
      this->GrocerItems.emplace(item, 1);
    }
  }
}

/*
 * This function handles printing the individual item frequency if it is in
 * the data, otherwise it prints the item name with the value of 0 to indicate
 * it is not present.
 */
void GrocerTracker::PrintItemFrequency() const {
  string userInput = ""; // User Selected item for printing
  cout << "Enter item to search: ";
  getline(cin, userInput);

  auto checkItem = this->GrocerItems.find(userInput);
  if (checkItem != this->GrocerItems.end()) {
    cout << checkItem->first << " " << checkItem->second << endl;
  } else {
    cout << userInput << " " << 0 << endl;
  }
}

/*
 * This function handles printing the all item frequencies if it is in the
 * data, otherwise it prints the item name with the value of 0 to indicate it
 * is not present.
 */
void GrocerTracker::PrintItemFrequencies() const {
  for (const auto &[key, value] : this->GrocerItems) {
    cout << key << " " << value << endl;
  }
}

/*
 * This function handles printing the item frequencies if it is in the
 * data in a histogram format.
 */
void GrocerTracker::PrintItemHistogram() const {
  for (const auto &[key, value] : this->GrocerItems) {
    cout << setw(this->MaxNameLength + 1) << " ";
    printCharNTimes('*', value);
    cout << endl;
    cout << setw(this->MaxNameLength) << right << key << " ";
    printCharNTimes('*', value);
    cout << endl;
    cout << setw(this->MaxNameLength + 1) << " ";
    printCharNTimes('*', value);
    cout << endl;
  }
}
