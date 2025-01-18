#include <iostream>

// This is a simplified example, and you will need to adapt it to your specific
// graphics library
void fillOval(int x, int y, int width, int height) {
    cout << "Drawing filled oval at (" << x << ", " << y << ") with width "
         << width << " and height " << height << endl;
}

int main() {
    fillOval(100, 100, 200, 200);
    return 0;
}
