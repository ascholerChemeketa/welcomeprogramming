#include <iostream>
using namespace std;

int main() {
    int x = 12;

    // This is not going to work as expected!!!
    if (x < 0)
        cout << "x is negative" << endl;
    cout << "it is less than 0" << endl;
}