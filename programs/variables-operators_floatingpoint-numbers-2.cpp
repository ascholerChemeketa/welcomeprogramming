#include <iomanip>
#include <iostream>

int main() {
  double minute = 59.0;
  cout << fixed << setprecision(2)
       << "Fraction of the hour that has passed: " << minute / 60.0 << endl;
  return 0;
}