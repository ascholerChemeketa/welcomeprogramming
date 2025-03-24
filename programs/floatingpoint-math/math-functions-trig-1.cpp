#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double angleDegrees = 90;
    double angleRadians = angleDegrees / 180.0 * numbers::pi;
    cout << "90 degrees is " << angleRadians << " radians." << endl;
    // To get the correct answer, we need to pass the function radians instead of degrees
    cout << "The sine of 90 degrees is " << sin(angleRadians) << endl;
}

