#include <iostream>

// Needed for the sin and cos functions
#include <cmath>

using namespace std;

int main() {
    cout << "Enter a number of degrees: ";
    double thetaDegrees;
    cin >> thetaDegrees;

    const double PI = acos(-1.0);  //calculate an accurate value of PI

    double thetaRadians = thetaDegrees * PI / 180;
    double sinValue = sin(thetaRadians);
    double cosValue = cos(thetaRadians);

    double x = 2;
    double y = 4;

    double x2 = x * cosValue - y * sinValue;
    cout << "x2: " << x2 << endl;
    double y2 = x * sinValue + y * cosValue;
    cout << "y2: " << y2 << endl;
}