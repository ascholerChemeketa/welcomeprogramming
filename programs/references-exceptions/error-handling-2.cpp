#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool stringToBool(const string& s) {
    assert(s == "true" || s == "false");
    if (s == "true") {
        return true;
    } else if (s == "false") {
        return false;
    }
    return false; // ??????
}

int main() {
    bool result = stringToBool("cat");
    cout << "Result is " << result << endl;
}