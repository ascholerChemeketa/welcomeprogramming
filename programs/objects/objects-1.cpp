#include <iostream>
#include <string>
#include <format>
using namespace std;

// A point struct
struct Point {
    double x, y;
};


// Create a point
Point createPoint(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

// Shift a point
void shiftPoint(Point& p, 
                double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

// Get a string representation of the point
string toString(const Point& p) {
    return format("({}, {})", p.x, p.y);
}

int main() {
    // Example usage
    Point p1 = createPoint(3.0, 4.0);
    cout << "Point 1: " 
         << toString(p1) << endl;
    shiftPoint(p1, 1.0, 2.0);
    cout << "Point 1 after shift: " 
         << toString(p1) << endl;
}