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

    // Method to shift the point
    void shift(double dx, double dy) {
        m_x += dx;
        m_y += dy;
    }

    // Method to get a string representation of the point
    string toString() {
        return format("({}, {})", m_x, m_y);
    }

private:
    double m_x, m_y;
};

int main() {
    // Example usage
    Point p1(3.0, 4.0);
    cout << "Point 1: " << p1.toString() << endl;
    p1.shift(1.0, 2.0);
    cout << "Point 1 after shift: " << p1.toString() << endl;
}