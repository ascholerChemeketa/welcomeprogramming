/* This function calculates the center point of a rectangle. */
#include <iostream>
// Assuming Point and Rectangle structures exist. If not, define them.
struct Point {
  double x, y;
};
struct Rectangle {
  double x, y, width, height;
};
Point findCenter(Rectangle box) {
  Point center;
  center.x = box.x + box.width / 2.0;
  center.y = box.y + box.height / 2.0;
  return center;
}