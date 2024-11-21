#include <iostream>

void nLines(int n) {
  if (n > 0) {
    cout << endl;
    nLines(n - 1);
  }
}