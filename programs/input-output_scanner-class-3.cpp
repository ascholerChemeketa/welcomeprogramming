#include <iostream>
#include <string>

using namespace std;

int main() {
  string line;
  cout << "Type something: ";
  getline(cin, line);
  cout << "You said: " << line << endl;

  cout << "Type something else: ";
  getline(cin, line);
  cout << "You also said: " << line << endl;
  return 0;
}