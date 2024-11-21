#include <iostream>

void baffle() {
  cout << "test\n";
  for (int i = 0; i < -5; ++i) {
    cout << "ping\n";
  }
}

void zoop() {
  baffle();
  cout << "You wugga ";
  baffle();
}

int main() {
  zoop();
  return 0;
}
