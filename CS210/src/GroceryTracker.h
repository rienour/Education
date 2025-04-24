/**
 * Author Riley Eichenour
 * Assignment: Project Three
 * Purpose: The purpose of this program is to demonstrate student competency to
 * design class and functional programs that comply with industry regulations.
 * This will be demonstrated through an example grocery tracker utility.
 */
#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <fstream>
#include <map>
#include <string>

class GrocerTracker {
private:
  std::map<std::string, int> GrocerItems;
  unsigned int MaxNameLength = 0;

public:
  GrocerTracker() = default;
  GrocerTracker(std::map<std::string, int>);
  void ReadInputData(std::ifstream &);
  void WriteOutputData(std::ofstream &) const;
  void PrintItemFrequency() const;
  void PrintItemFrequencies() const;
  void PrintItemHistogram() const;
};

void printCharNTimes(char, unsigned short);
bool isInRangeInclusive(short, short, short);
void dispatchMenuEntry(short menuEntry, const GrocerTracker &);
void printMenu();
short getShort(std::string, short, short);
void openInputFile(std::ifstream &, const std::string);
void openOutputFile(std::ofstream &, const std::string);

#endif // GROCERYTRACKER_H
