#include <cmath>
#include <iostream>
#include <string>
#include <format>
using namespace std;

// A point class with const used in the member function
class Point {
public:
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    }

    double getX() const {
        return m_x;
    }

    double getY() const {
        return m_y;
    }

    void setX(double x) {
        m_x = x;
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

    string toString() const {
        return format("({}, {})", getX(), getY());
    }

private:
    double m_x, m_y;
};