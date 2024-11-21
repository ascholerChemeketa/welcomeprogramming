#include <iostream>

void zippo(const string& s, int n) {
  for (int i = 0; i < n; ++i) {
    cout << s << endl;
  }
}

int main() {
  zippo("rattle", 13);
  return 0;
}