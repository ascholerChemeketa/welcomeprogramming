#include <iomanip>
#include <iostream>
int main() {
  double y = 1.0 / 3.0;
  cout << fixed << setprecision(10) << y
            << endl; // prints 0.3333333333
  return 0;
}