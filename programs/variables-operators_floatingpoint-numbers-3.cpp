#include <iostream>

int main() {
  // int x = 1.1; // Compiler error: Cannot implicitly convert double to int
  double x = 1.1;              // Correct
  int y = static_cast<int>(x); // Correct with explicit cast
  cout << y << endl;           // prints 1
  return 0;
}