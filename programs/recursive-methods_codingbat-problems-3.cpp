#include <iostream>
#include <string>

string noX(const string& str) {
    if (str.empty()) {
        return "";
    }
    char first = str[0];
    string rest = str.substr(1);
    string recurse = noX(rest);
    if (first == 'x') {
        return recurse;
    } else {
        return first + recurse;
    }
}