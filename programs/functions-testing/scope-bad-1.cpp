#include <iostream>
using namespace std;

int doubleValue(int num) {
    int result = 2 * x;   // Error: 'x' is not defined in this scope
    return result;
}

int main() {
    int x = 5;
    int y = doubleValue(x);
    int z = doubleValue(12);
    cout << y << endl;
    cout << z;
}