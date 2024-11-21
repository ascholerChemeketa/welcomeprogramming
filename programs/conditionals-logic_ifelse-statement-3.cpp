/*
 * This code checks if a number is even or odd and prints the result to the
 * console.
 */
#include <iostream>
using namespace std;

int main() {
  int x;
  // Get input from the user
  cout << "Enter an integer: ";
  cin >> x;

  // Check if x is even or odd
  if (x % 2 == 0) {
    cout << "x is even" << endl;
  } else {
    cout << "x is odd" << endl;
  }
  return 0;
}