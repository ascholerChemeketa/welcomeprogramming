#include <iostream>
#include <string>

int main() {
  string text = "";
  for (int i = 0; i < 10; i++) {
    string line;
    getline(cin, line);
    text += line + '\n';
  }
  cout << "You entered:\n" << text;
  return 0;
}