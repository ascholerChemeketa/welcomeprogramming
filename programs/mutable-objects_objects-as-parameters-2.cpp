/* This function calculates the Euclidean distance between two points. */
#include <cmath>
#include <iostream>

// Assuming Point structure exists. If not, define it.
struct Point {
  double x, y;
};

double distance(Point p1, Point p2) {
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}