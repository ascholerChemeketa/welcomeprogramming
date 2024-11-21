#include <iostream>

void ping(const string& strangStrung) {
  cout << "any " << strangStrung << "more \n";
}

void baffle() {
  cout << "wug";
  ping();
}

void zippo(const string& quince, int flag) {
  if (flag < 0) {
    cout << quince << " zoop\n";
  } else {
    cout << "ik\n";
    baffle();
    cout << "boo-wa-ha-ha\n";
  }
}

void zoop() {
  baffle();
  cout << "You wugga ";
  baffle();
}

void zoop(const string& fred, int bob) {
  cout << fred << endl;
  if (bob == 5) {
    ping("not ");
  } else {
    cout << "!\n";
  }
}

void ping() {
  cout << ".\n";
}

void clink(int fork) {
  cout << "It's ";
  for (int i = 0; i < fork; ++i) {
    cout << "breakfast ";
  }
}

int main() {
  int bizz = 5;
  int buzz = 2;
  zoop("just for", bizz);
  clink(2 * buzz);
  return 0;
}
