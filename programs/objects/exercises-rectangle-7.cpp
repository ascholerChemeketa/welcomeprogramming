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

    /**
     * @brief Multiply the width and height of the rectangle by a scale factor.
     * 
     * @param scaleFactor amount to scale the rectangle by. If negative, no scaling is done.
     */
    void scale(double scaleFactor);
