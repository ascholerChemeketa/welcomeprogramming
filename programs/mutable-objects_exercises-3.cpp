/* This main function creates a Point and a Rectangle. It then finds the center
 * of the rectangle using the findCenter function (which is assumed to be
 * defined elsewhere), calculates the distance between the center and the Point
 * using the distance function (also assumed to be defined elsewhere), and
 * prints the distance. */
#include <cmath>
#include <iostream>

// Assuming Point and Rectangle structures exist. If not, define them.
struct Point {
  double x, y;
};

struct Rectangle {
  double x, y, width, height;
};

Point findCenter(Rectangle rect) {
  Point center;
  center.x = rect.x + rect.width / 2.0;
  center.y = rect.y + rect.height / 2.0;
  return center;
}

double distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
  Point blank = {5, 8};
  Rectangle rect = {0, 2, 4, 4};
  Point center = findCenter(rect);
  double dist = distance(center, blank);
  cout << dist << endl;
  return 0;
}