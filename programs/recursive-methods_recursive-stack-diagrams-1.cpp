#include <iostream>
#include <stdexcept>

void forever(const string& s) {
    cout << s << endl;
    forever(s);
}