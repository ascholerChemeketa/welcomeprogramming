/* This string represents a java.awt.Rectangle object.  It shows the rectangle's
 * properties: x and y coordinates of its top-left corner (-50, -50), width
 * (200), and height (300). */
#include <iostream>

// A simple representation of a rectangle.  In a real application you'd use a
// more robust structure.
struct Rectangle {
    int x, y, width, height;
};

int main() {
    Rectangle rect = {-50, -50, 200, 300};
    cout << "Rectangle: x=" << rect.x << ", y=" << rect.y
         << ", width=" << rect.width << ", height=" << rect.height << endl;
    return 0;
}