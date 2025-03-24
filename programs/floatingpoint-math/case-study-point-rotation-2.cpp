#include <iostream>

// Needed for the sin and cos functions
#include <cmath>

using namespace std;

int main() {
    double thetaDegrees = 45;

    double thetaRadians = thetaDegrees * numbers::pi / 180;
    cout << "thetaRadians: " << thetaRadians << endl;
    double sinValue = sin(thetaRadians);
    cout << "sinValue: " << sinValue << endl;
}