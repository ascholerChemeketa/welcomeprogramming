#include <iostream>
using namespace std;

class Point {
public:
    Point(double x, double y) {
        // A new point is created when we enter the constructor
        m_x = x;
        m_y = y;
        // implicit return of the new point
    }
private:
    double m_x, m_y;
};

int main() {
    // Constuct a point
    Point p1 = Point(3.0, 4.0);
    // Constuct a point, preferred syntax
    Point p2(1.0, 2.0);
}