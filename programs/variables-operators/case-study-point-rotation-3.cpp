#include <iostream>

// Needed for the sin and cos functions
#include <cmath>

using namespace std;

int main() {
    double thetaDegrees = 45;
    const double PI = acos(-1.0);  //calculate an accurate value of PI
    cout << "PI: " << PI << endl;

    double thetaRadians = thetaDegrees * PI / 180;
    cout << "thetaRadians: " << thetaRadians << endl;
    double sinValue = sin(thetaRadians);
    cout << "sinValue: " << sinValue << endl;
    double cosValue = cos(thetaRadians);
    cout << "cosValue: " << cosValue << endl;

    double x = 2;
    double y = 4;

    double x2 = x * cosValue - y * sinValue;
    cout << "x2: " << x2 << endl;
}