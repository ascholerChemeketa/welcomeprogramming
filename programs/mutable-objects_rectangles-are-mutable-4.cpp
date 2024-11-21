#include <iostream>
struct Rectangle {
  double x, y, width, height;
  void translate(double dx, double dy) {
    x += dx;
    y += dy;
  }
};
int main() {
  Rectangle box = {0, 0, 100, 200};
  box.translate(50, 100);
  cout << "(" << box.x << ", " << box.y << ", " << box.width << ", "
            << box.height << ")" << endl; // Output: (50, 100, 100, 200)
  return 0;
}