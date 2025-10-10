#include <iostream>
using namespace std;

//global variables:
const double PI = 3.14;  // a constant value of PI available everywhere
int badGlobalVariable = 5;     // NO NO NO!!! non-const variables should NOT be global

double timesPI(double num) {
    // we can use the global constant PI here:
    return num * PI;
}

int main() {
    int x = 5;
    double xTimesPi = timesPI(x);
    // we can use also the global constant PI here:
    cout << x << " times " << PI << " is " << xTimesPi << endl;
}