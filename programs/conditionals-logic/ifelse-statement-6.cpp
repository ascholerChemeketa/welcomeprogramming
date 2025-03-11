#include <iostream>
using namespace std;

int main() {
    int x = 1;
    // This is not going to work as expected!!!
    if (x % 2 == 0); {
        cout << "x is even\n";
    }
}