#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number of inches: ";
    int inches;
    cin >> inches;

    const double CM_PER_INCH = 2.54;
    double cm = inches * CM_PER_INCH;
    cout << "That is " << cm << " centimeters." << endl;
}