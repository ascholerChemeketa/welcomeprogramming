#include <iostream>
#include <string>

void func(const string& str) {
  if (!str.empty()) {
    char first = str[0];
    string rest = str.substr(1);
    cout << "First: " << first << endl;
    cout << "Rest: " << rest << endl;
  }
}