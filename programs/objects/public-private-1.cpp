#include <iostream>
using namespace std;

// A point class
class Point {
public:
    // Construct a point
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    }
private:
    double m_x, m_y;
};

int main() {
    // Constuct a point
    Point p1(3.0, 4.0);
    cout << p1.m_x; // Error: m_x is private!
}