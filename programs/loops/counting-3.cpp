#include <iostream>
using namespace std;

int main() {
    int line = 0;
    while (line < 5) {
        // line controls now many times we print
        // but we never see its value
        cout << "Hello" << endl;
        ++line;
    }
}