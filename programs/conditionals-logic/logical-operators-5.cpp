#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (b != 0 && a % b == 0) {
        cout << "a is divisible by b" << endl;
    }
    else {
        cout << "a is not divisible by b" << endl;
    }
}