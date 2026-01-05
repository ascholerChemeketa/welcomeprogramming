#include <iostream>
#include <stdexcept>
using namespace std;

class Rectangle {
public:
    Rectangle() {
      // nothing to do
    }

    Rectangle(double width, double height);

    double getArea();

    void setWidth(double width) {
        m_width = width;
    }
    void setHeight(double height) {
        m_height = height;
    }

    double getWidth() {
        return m_width;
    }
    double getHeight() {
        return m_height;
    }

    void scale(double scaleFactor);
