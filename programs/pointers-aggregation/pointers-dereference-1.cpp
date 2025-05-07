#include <iostream>
using namespace std;

int main() {
    int x = 10;
    cout << "Address of x is " << &x << endl;
    cout << "Value of x is " << x << endl;

    int* p = &x; // p points at x
    cout << "Value of p is " << p << endl;
    cout << "Value of *p is " << *p << endl;
}