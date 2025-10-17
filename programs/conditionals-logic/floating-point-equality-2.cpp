#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 5.03;
    double b = 5.00 + 0.01 + 0.01 + 0.01;

    const double EPSILON = 0.0001;
    if (abs(a - b) < EPSILON) {
        cout << "a and b are pretty much equal" << endl;
    } else {
        cout << "a and b are NOT close enough to equal" << endl;
    }
}