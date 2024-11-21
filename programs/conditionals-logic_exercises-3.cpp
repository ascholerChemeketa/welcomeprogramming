#include <iostream>

using namespace std;

// Assume isHoopy and isFrabjuous are defined elsewhere
bol isHoopy(int x);
bol isFrabjuous(int x);

int main() {
  bool flag1 = isHoopy(202);
  bool flag2 = isFrabjuous(202);
  cout << flag1 << endl;
  cout << flag2 << endl;
  if (flag1 && flag2) {
    cout << "ping!" << endl;
  }
  if (flag1 || flag2) {
    cout << "pong!" << endl;
  }
  return 0;
}