#include <iostream>

using namespace std;

int main() {
  unsigned long int weirdInput = 0;

  cin >> weirdInput;

  while(weirdInput != 1) {
    // Print the current weird input as part of the out string
    cout << weirdInput << " ";

    // Check if weird input is even to determine operation
    if(weirdInput % 2 == 0) {
      weirdInput >>= 1;
    } else {
      weirdInput *= 3;
      weirdInput ++;
    }
  }
  cout << weirdInput << endl;

  return 0;
}
