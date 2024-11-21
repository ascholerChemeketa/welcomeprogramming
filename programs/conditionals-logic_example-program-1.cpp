#include <cmath>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
  // prompt for input
  double x;
  cout << "Enter a number: ";
  cin >> x;

  // check the format
  if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string word;
    cin >> word;
    cerr << word << " is not a number\n";
    return 1; // Indicate an error
  }

  // check the range
  if (x > 0) {
    double y = log(x);
    cout << "The log is " << y << endl;
  } else {
    cout << "The log is undefined\n";
  }
  return 0;
}