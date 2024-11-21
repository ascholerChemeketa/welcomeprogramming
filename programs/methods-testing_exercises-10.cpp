#include <iostream>

void zoop(const string& s, int n) {
  for (int i = 0; i < n; ++i) {
    cout << s;
  }
}

void clink(int fork) {
  cout << "It's ";
  zoop("breakfast ", fork);
}

int main() {
  // This main function is just to show an example of how to call the clink
  // function
  clink(3);
  return 0;
}
