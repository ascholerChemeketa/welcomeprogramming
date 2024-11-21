/* This main function creates a Rectangle object, finds its center using
 * findCenter (assumed to be defined elsewhere), prints the center's coordinates
 * using printPoint (also assumed to be defined elsewhere), grows the rectangle,
 * finds the new center, and prints the new coordinates. */
#include <iostream>

// Assuming Point and Rectangle structures exist.  If not, define them.
struct Point {
  double x, y;
};

struct Rectangle {
  double x, y, width, height;

  void grow(double w, double h) {
    width += w;
    height += h;
  }
};

Point findCenter(Rectangle rect) {
  Point center;
  center.x = rect.x + rect.width / 2.0;
  center.y = rect.y + rect.height / 2.0;
  return center;
}

void printPoint(Point p) {
  cout << "(" << p.x << ", " << p.y << ")" << endl;
}

int main() {
  Rectangle box1 = {2, 4, 7, 9};
  Point p1 = findCenter(box1);
  printPoint(p1);
  box1.grow(1, 1);
  Point p2 = findCenter(box1);
  printPoint(p2);
  return 0;
}