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

    double getX() {
        return m_x;
    }

    double setX(double x) {
        m_x = x;
    }

private:
    double m_x, m_y;
};

int main() {
    Point p1(3.0, 4.0);
    cout << p1.getX() << endl;

    Point p2(5.0, 1.0);
    cout << p2.getX() << endl;
}