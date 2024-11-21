/* This code checks if a number is positive and prints the result to the
 * console.  It also always prints that x is not zero, regardless of x's value.
 */
#include <iostream>
using namespace std;

int main() {
  int x;
  // Get input from the user
  cout << "Enter an integer: ";
  cin >> x;

  // Check if x is positive
  if (x > 0) {
    cout << "x is positive" << endl;
  }
  cout << "x is not zero" << endl; // This line will always execute
  return 0;
}