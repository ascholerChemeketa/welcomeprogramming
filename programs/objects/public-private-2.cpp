#include <iostream>
#include <string>
#include <format>
using namespace std;

// A point class
class Point {
public:
    // Construct a point
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    }

    double getX() {
      return m_x;
    }

public:
    double m_x, m_y;
};

int main() {
    // Constuct a point
    Point p1(3.0, 4.0);
    // Use a public method to access private data
    cout << p1.getX();
    // p1.m_x = 5.0; // Still an error: m_x is private!
}