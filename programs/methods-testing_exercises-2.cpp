#include <iostream>

void zippo(const string& s, int n) {
  for (int i = 0; i < n; ++i) {
    cout << s << endl;
  }
}

void ping(const string& strangStrung) {
  cout << "any " << strangStrung << "more \n";
}

void baffle(const string& blimp) {
  cout << blimp << endl;
  zippo("ping", -5);
}

int main() {
  // Example to call the baffle function
  baffle("test");
  return 0;
}
