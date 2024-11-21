#include <iostream>

void displayBinary(int value) {
  if (value > 0) {
    displayBinary(value / 2);
    cout << value % 2;
  }
}