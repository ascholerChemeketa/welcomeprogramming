#include <iostream>
void countdown(int n) {
  if (n == 0) {
    cout << "Blastoff!\n";
  } else {
    cout << n << "\n";
    countdown(n - 1);
  }
}