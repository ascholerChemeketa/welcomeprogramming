#include <iostream>
using namespace std;

int main() {
    int x = 10;
    cout << "Address of x is " << &x << endl;

    double* p = &x; // p is a pointer to a double, try to initialize to the address of x
    cout << "Value of p is " << p << endl;
}