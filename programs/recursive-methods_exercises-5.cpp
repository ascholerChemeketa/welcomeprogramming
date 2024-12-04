#include <iostream>
#include <string>

string middle(const string& s) {
    if (s.length() <= 2) {
        return "";
    }
    return s.substr(1, s.length() - 2);
}