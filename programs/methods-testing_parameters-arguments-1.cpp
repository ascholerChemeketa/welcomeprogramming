#include <iostream>

void printTwice(const string& s) {
  cout << s << endl;
  cout << s << endl;
}

int main() {
  printTwice("Don't make me say this twice!");
  return 0;
}
