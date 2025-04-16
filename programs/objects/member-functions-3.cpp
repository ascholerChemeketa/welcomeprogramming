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

    void setX(double x) {
        m_x = x;
    }

    double getY() {
        return m_y;
    }

    void setY(double y) {
        m_y = y;
    }

    void shift(double dx, double dy) {
        setX(getX() + dx);
        setY(getY() + dy);
        // or
        // m_x += dx;
        // m_y += dy;
    }

    string toString() {
        return format("({}, {})", getX(), getY());
    }

private:
    double m_x, m_y;
};

int main() {
    Point p1(3.0, 4.0);
    cout << "Point 1: " << p1.toString() << endl;
    p1.shift(1.0, 2.0);
    cout << "Point 1 after shift: " << p1.toString() << endl;
    p1.setX(5.0);
    cout << "Point 1 after setX: " << p1.toString() << endl;
}