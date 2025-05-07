#include <iostream>
using namespace std;

int main() {
    int x = 10;
    cout << "Address of x is " << &x << endl;

    int* p = x; // p is a pointer to an int, try to initialize with the value x has
    cout << "Value of p is " << p << endl;
}