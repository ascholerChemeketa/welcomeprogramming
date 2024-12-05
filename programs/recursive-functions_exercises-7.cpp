#include <algorithm>
#include <iostream>

string reverseString(const string& str) {
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return reversed_str;
}

int main() {
    string backwards = reverseString("coffee");
    cout << backwards << endl;
    return 0;
}