#include <iostream>
#include <cmath>
using namespace std;

// A point class
class Point {
public:
    // Construct a point
    Point(double x, double y) {
        // Convert x and y to polar coordinates
        m_distance = sqrt(x * x + y * y);
        m_angle = atan2(y, x);
        // Bug... we are not correctly handling y == 0
    }

    double getX() {
      double x = m_distance * cos(m_angle);
      return x;
    }

public:
    double m_angle;
    double m_distance;
};

int main() {
    // Constuct a point
    Point p1(3.0, 4.0);
    // Use a public method to access private data
    cout << p1.getX();
}