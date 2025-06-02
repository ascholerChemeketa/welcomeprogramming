module;

#include <format>
#include <string>

import GeometricObject;

export module Circle;

using namespace std;

export class Circle : public GeometricObject {
private:
    double m_radius;

public:
    Circle(double radius, string color);

    // same idea as Rectangle, but we will do different math
    double getArea() const;

    virtual string toString() const;
};

Circle::Circle(double radius, string color)
    : GeometricObject(color) {
    m_radius = radius;
}

double Circle::getArea() const {
    return std::numbers::pi * m_radius * m_radius;
}

string Circle::toString() const {
    return format("A {} circle with a radius of {}.", m_color, m_radius);
}
