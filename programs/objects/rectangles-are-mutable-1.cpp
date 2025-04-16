#include <iostream>

struct Rectangle {
    double x, y, width, height;
};

int main() {
    Rectangle box = {0, 0, 100, 200};
    box.x = box.x + 50;
    box.y = box.y + 100;
    cout << box.x << ", " << box.y << endl; // prints 50, 100
    return 0;
}