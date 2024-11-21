#include <iostream>
#include <string>

char first(const string& s) {
  if (s.empty()) {
    throw invalid_argument("String is empty");
  }
  return s[0];
}