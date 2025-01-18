#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double pi = acos(-1.0);

    double opposite = 2;
    double adjacent = 2;
    double angleRadians = atan(opposite / adjacent);
    // The result of atan was in radians, so we need to convert it to degrees
    double angleDegrees = angleRadians * 180.0 / pi;
    cout << "The measure in degrees is " << angleDegrees << endl;
}

