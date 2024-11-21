#include <iostream>
int main() {
  int a = 5;
  int b = a;                               // a and b are now equal
  a = 3;                                   // a and b are no longer equal
  cout << a << " " << b << endl; // Prints 3 5
  return 0;
}