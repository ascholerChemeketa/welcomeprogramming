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
}