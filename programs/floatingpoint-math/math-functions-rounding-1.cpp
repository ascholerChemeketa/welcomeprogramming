#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double testValue = 4.82;
    cout << "truc(" << testValue << ") = " << trunc(testValue) << endl;
    cout << "floor(" << testValue << ") = " << floor(testValue) << endl;
    cout << "ceil(" << testValue << ") = " << ceil(testValue) << endl;
    cout << "round(" << testValue << ") = " << round(testValue) << endl;
}