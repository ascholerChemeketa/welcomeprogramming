#include <iostream>

struct Rectangle {
  double x, y, width, height;
};

void moveRect(Rectangle& box, double dx, double dy) {
  box.x = box.x + dx;
  box.y = box.y + dy;
}

int main() {
  Rectangle box = {0, 0, 100, 200};
  moveRect(box, 50, 100);
  cout << "(" << box.x << ", " << box.y << ", " << box.width << ", "
       << box.height << ")" << endl; // prints (50, 100, 100, 200)
  return 0;
}