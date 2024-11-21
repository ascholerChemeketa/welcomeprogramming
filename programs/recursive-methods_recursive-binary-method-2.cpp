#include <iostream>

void displayBinary(int value) {
  if (value > 0) {
    displayBinary(value / 2);
    cout << value % 2;
  }
}

int main() {
  displayBinary(23); // output is 10111
  cout << endl;
  return 0;
}