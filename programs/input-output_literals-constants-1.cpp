#include <iostream>
#include <limits>

using namespace std;

int main() {
  int inch;
  double cm;
  cout << "Enter the number of inches: ";
  cin >> inch;

  // Input validation. If input fails, clear error flags and discard the bad
  // input
  if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Invalid input. Please enter a valid integer.\n";
    return 1; // Indicate an error
  }

  const double CM_PER_INCH = 2.54;
  cm = inch * CM_PER_INCH;
  printf("%d in = %f cm\n", inch, cm);
  return 0;
}