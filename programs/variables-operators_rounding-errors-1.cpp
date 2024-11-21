#include <iomanip>
#include <iostream>
int main() {
  cout << fixed << setprecision(20) << 0.1 * 10 << endl;
  cout << fixed << setprecision(20)
            << 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1
            << endl;
  return 0;
}