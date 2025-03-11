#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Calculates the area of a triangle using Heron's formula.
 * @param a Length of the first side of the triangle.
 * @param b Length of the second side of the triangle.
 * @param c Length of the third side of the triangle.
 * @return The area of the triangle.
 */
double heronsFormula(double a, double b, double c) {
    // Calculate the semi-perimeter s
    double s = (a + b + c) / 2.0;
    // Calculate the area using Heron's formula
    double area = sqrt((s - a) * (s - b) * (s - c));
    return area;
}

int main() {
    cout << "heronsFormula(3, 4, 5), expect 6 = " << heronsFormula(3, 4, 5) << endl;
    cout << "heronsFormula(2.5, 4.1, 6.25), expect 3.20322 = " << heronsFormula(2.5, 4.1, 6.25) << endl;
    cout << "heronsFormula(2.5, 4.1, 6.25), expect 0 = " << heronsFormula(0, 3, 3) << endl;
}
