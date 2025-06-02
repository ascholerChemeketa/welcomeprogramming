module;

#include <format>
#include <string>

import GeometricObject;

export module Rectangle;

using namespace std;

export class Rectangle : public GeometricObject {
private:
    double m_width;
    double m_height;

public:
    Rectangle(double width, double height, string color);

    // provide an implementation of the getArea function
    //  it is no longer abstract
    virtual double getArea() const;

    // override the getStr function
    virtual string toString() const;
};

Rectangle::Rectangle(double width, double height, string color)
  : GeometricObject(color) {
    m_width = width;
    m_height = height;
}

double Rectangle::getArea() const {
    return m_width * m_height;
}

string Rectangle::toString() const {
    return format("A {} rectangle with dimensions of {} by {}.", 
                  getColor(),
                  m_width,
                  m_height);
}