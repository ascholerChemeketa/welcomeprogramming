#include <iostream>
using namespace std;

class Point {
public:
    Point(int x, int y) {
        m_x = x;
        m_y = y;
    }

    Point() {}

    double getX() {
        return m_x;
    }

    double getY() {
        return m_y;
    }

    void shift(double deltaX, double deltaY) {
        m_x += deltaX;
        m_y += deltaY;
    }

private:
    double m_x = 0;
    double m_y = 0;
};