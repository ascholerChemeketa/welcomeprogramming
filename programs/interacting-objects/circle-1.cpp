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

private:
    double m_radius;
    Point m_center;
};

int main() {
    Circle c1(5.0, 2, 1);
}