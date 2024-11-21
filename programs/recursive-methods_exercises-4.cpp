#include <iostream>
#include <string>
string rest(const string& s) {
  if (s.length() <= 1) {
    return "";
  }
  return s.substr(1);
}