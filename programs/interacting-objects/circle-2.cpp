#include <iostream>
//import the Point class
import Point;

using namespace std;

class Circle {
public:
    Circle(double radius, double x, double y) {
        m_radius = radius;
        m_center = Point(x, y);
    }

    double getRadius() const {
        return m_radius;
    }

    double getX() const {
        return m_center.getX();
    }

    double getY() const {
        return m_center.getY();
    }

private:
    double m_radius;
    Point m_center;
};

int main() {
    Circle c1(5.0, 2, 1);
    cout << c1.getRadius() << endl;
    cout << c1.getX() << endl;
    cout << c1.getY() << endl;
}