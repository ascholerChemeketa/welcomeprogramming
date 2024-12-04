#include <iomanip>
#include <iostream>

using namespace std;

constexpr double CM_PER_INCH = 2.54;
constexpr int IN_PER_FOOT = 12;

double toImperial(double cm) {
    return cm / CM_PER_INCH;
}

double toMetric(int feet, int inches) {
    return (feet * IN_PER_FOOT + inches) * CM_PER_INCH;
}

int main() {
    double cm, result;
    int feet, inches;

    // test the Imperial conversion
    cout << "Exactly how many cm? ";
    cin >> cm;
    result = toImperial(cm);
    cout << fixed << setprecision(2) << "That's " << result << " inches" << endl
         << endl;

    // test the Metric conversion
    cout << "Now how many feet? ";
    cin >> feet;
    cout << "And how many inches? ";
    cin >> inches;
    result = toMetric(feet, inches);
    cout << fixed << setprecision(2) << "That's " << result << " cm" << endl;
    return 0;
}