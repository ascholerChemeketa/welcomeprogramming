#include <iomanip>
#include <iostream>
int main() {
  int minute = 59;
  cout << "Fraction of the hour that has passed: " << fixed
            << setprecision(2) << (double)minute / 60 << endl;
  return 0;
}