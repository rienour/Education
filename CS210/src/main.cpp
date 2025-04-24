/**
 * Author Riley Eichenour
 * Assignment: Project Three
 * Purpose: The purpose of this program is to demonstrate student competency to
 * design class and functional programs that comply with industry regulations.
 * This will be demonstrated through an example grocery tracker utility.
 */

#include "GroceryTracker.h"

using namespace std;

// Filenames containing location and Fahrenheit temperature inputs
const string INPUT_FILENAME = "CS210_Project_Three_Input_File.txt";
const string OUTPUT_FILENAME = "frequency.dat";

int main() {
  ifstream inFile;  // Initialize input stream with input filename
  ofstream outFile; // Initialize output stream with output filename

  // Open the files to utilize for program data storage
  openInputFile(inFile, INPUT_FILENAME);
  openOutputFile(outFile, OUTPUT_FILENAME);

  GrocerTracker grocerItems = GrocerTracker(); // To store grocer information

  // Read the data present in the input file for the application
  grocerItems.ReadInputData(inFile);

  // Create a backup file of the read data
  grocerItems.WriteOutputData(outFile);

  short userSelection = 0;
  do {
    printMenu();
    userSelection = getShort("Select a menu option", 1, 4);
    dispatchMenuEntry(userSelection, grocerItems);
  } while (userSelection != 4);

  // Close files opened by the program
  inFile.close();
  outFile.close();

  return 0;
}
