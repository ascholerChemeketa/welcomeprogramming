#include <iostream>
#include <string>

using namespace std;

int* makeMemory() {
    int* p1 = new int(5);
    cout << "p1: " << p1 << endl;
    cout << "p1 points to: " << *p1 << endl;
    // Do NOT delete the memory p1 points at...
    // we will return that address and keep using it
    return p1;
}
