#include <iostream>
using namespace std;

int main() {
    double a = 5.03;
    double b = 5.00 + 0.01 + 0.01 + 0.01;

    if (a == b) {
        cout << "a and b are equal" << endl;
    } else {
        cout << "a and b are NOT equal" << endl;
    }
}