#include <iostream>
using namespace std;

//global variables:
const double PI = acos(-1.0);  // an accurate value of PI available everywhere
int badGlobalVariable = 5;     // non-const variables should NOT be global

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