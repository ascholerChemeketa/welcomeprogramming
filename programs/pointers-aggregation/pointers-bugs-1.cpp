#include <iostream>
using namespace std;

int main() {
    int x = 10;

    int* p; // p is a pointer to an int, not initialized
    cout << "Value of p is " << p << endl;
    // This may work and print out a value. Or it may crash the program.
    cout << "Value of *p is " << *p << endl;
}