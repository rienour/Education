//============================================================================
// Name        : HashTable.cpp
// Author      : Riley Eichenour
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 4-2 Hash Table
//============================================================================

#include <algorithm>
#include <climits>
#include <iostream>
#include <string> // atoi
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

const unsigned int DEFAULT_SIZE = 179;

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Hash Table class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a hash table with chaining.
 */
class HashTable {

private:
    // Define structures to hold bids
    struct Node {
        Bid bid;
        unsigned int key;
        Node *next;

        // default constructor
        Node() {
            key = UINT_MAX;
            next = nullptr;
        }

        // initialize with a bid
        Node(Bid aBid) : Node() {
            bid = aBid;
        }

        // initialize with a bid and a key
        Node(Bid aBid, unsigned int aKey) : Node(aBid) {
            key = aKey;
        }
    };

    vector<Node> nodes;

    unsigned int tableSize = DEFAULT_SIZE;

    unsigned int hash(int key);

public:
    HashTable();
    HashTable(unsigned int size);
    virtual ~HashTable();
    void Insert(Bid bid);
    void PrintAll();
    void Remove(string bidId);
    Bid Search(string bidId);
    size_t Size();
};

/**
 * Default constructor
 */
HashTable::HashTable() {
    // Initalize node structure by resizing tableSize
    this->nodes.resize(tableSize);
}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(unsigned int size) {
    // Initalize node structure by resizing tableSize
    this->nodes.resize(size);

    // Update the instance tableSize
    this->tableSize = size;
}


/**
 * Destructor
 */
HashTable::~HashTable() {
    // Allocate temporary node pointer for deletions
    Node* tempNode = nullptr;

    // Allocate starting node for each list
    Node* startNode = nullptr;

    // Iterate through each vector linked list
    for(int i = 0; i < this->nodes.size(); i++) {
      // Get the starting node next pointer
      startNode = this->nodes.at(i).next;

      // Traverse the linked list to delete all heap allocated nodes
      while(startNode != nullptr) {
        tempNode = startNode;
        startNode = tempNode->next;
        delete tempNode;
      }
    }
    
    // Erase the memory allocated by the nodes vector
    this->nodes.clear();
}

/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * The key is calculated based on the key
 * modulo the tableSize of the instance.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(int key) {
    return key % (this->tableSize);
}

/**
 * Insert a bid
 *
 * @param bid The bid to insert
 */
void HashTable::Insert(Bid bid) {
  // Calculate the key for the given bid
  unsigned int bidKey = this->hash(atoi(bid.bidId.c_str()));

  // Retrieve the first node in the bucket
  Node* node = &this->nodes.at(bidKey);

  // If the bucket doesn't have items already
  if(node->key == UINT_MAX) {
    // Assign this node to the key position
    nodes.at(bidKey) = Node(bid, bidKey);
  }
  // Otherwise append a new node to the end of the list
  else {
    // Traverse to the end of the list to find tail
    while(node->next != nullptr){
      node = node->next;
    }

    // Append new node to the list
    node->next = new Node(bid, bidKey);
  }
}

/**
 * Print all bids
 */
void HashTable::PrintAll() {
  // Iterate through each bucket
  for(vector<HashTable::Node>::iterator i = this->nodes.begin(); i != this->nodes.end(); i++) {
    // Get the current list head node
    Node curListNode = *i;

    // If the key is not the default
    if(curListNode.key != UINT_MAX) {
      cout <<
        "Key: " << curListNode.key <<
        " | " << curListNode.bid.bidId <<
        " | " << curListNode.bid.title <<
        " | " << curListNode.bid.amount <<
        " | " << curListNode.bid.fund <<
        endl;

      // If there are collision keys to print
      while(curListNode.next != nullptr) {
        cout <<
          curListNode.key <<
          "> | " << curListNode.bid.bidId <<
          " | " << curListNode.bid.title <<
          " | " << curListNode.bid.amount <<
          " | " << curListNode.bid.fund <<
          endl;

        // Assign iteration node to the next node
        curListNode = *(curListNode.next);
      }
    }
  }
}

/**
 * Remove a bid
 *
 * @param bidId The bid id to search for
 */
void HashTable::Remove(string bidId) {
    // Set key equal to hash atoi bidID cstring
    unsigned int bidKey = this->hash(atoi(bidId.c_str()));

    // Get reference to first node in bucket
    Node* curNode = &this->nodes.at(bidKey);

    // Special case where the head is the target and only item in bucket
    if(curNode->bid.bidId == bidId && curNode->next == nullptr) {
      // Update the bucket to the empty state
      this->nodes.at(bidKey) = Node();

      // Early return since the item has been removed
      return;
    }

    // Traverse the bucket to locate the target node
    while(curNode->next != nullptr) {
      // If the next node is the target node
      if(curNode->next->bid.bidId == bidId) {
        // Create temporary pointer to target node
        Node* tempNode = curNode->next;

        // Move the pointer of the node prior to the target node
        curNode->next = tempNode->next;

        // Delete memory allocate to tempNode
        delete tempNode;

        // Early return since the target id has been removed
        return;
      }

      // Increment the target pointer
      curNode = curNode->next;
    }
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid HashTable::Search(string bidId) {
    Bid bid;

    // FIXME (7): Implement logic to search for and return a bid

    // create the key for the given bid
    // if entry found for the key
         //return node bid

    // if no entry found for the key
      // return bid
    // while node not equal to nullptr
        // if the current node matches, return it
        //node is equal to next node

    return bid;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, HashTable* hashTable) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            hashTable->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98223";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
        bidKey = "98223";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a hash table to hold all the bids
    HashTable* bidTable;

    Bid bid;
    bidTable = new HashTable();
    
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, bidTable);

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bidTable->PrintAll();
            break;

        case 3:
            ticks = clock();

            bid = bidTable->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
                cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 4:
            bidTable->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
