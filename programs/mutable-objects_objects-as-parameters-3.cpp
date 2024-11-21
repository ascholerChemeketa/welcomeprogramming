/* This code snippet creates two Point objects, p1 and p2, and then calculates
 * the distance between them using the distance method (which is assumed to be a
 * member method of the Point class). The result is stored in the dist variable,
 * which is expected to be 5.0.  In C++, you would typically define a separate
 * distance function as shown in the previous example. */
#include <cmath>
#include <iostream>
struct Point {
  double x, y;
  double distance(Point p2) {
    double dx = p2.x - x;
    double dy = p2.y - y;
    return sqrt(dx * dx + dy * dy);
  }
};
int main() {
  Point p1 = {0, 0};
  Point p2 = {3, 4};
  double dist = p1.distance(p2);
  cout << dist << endl; // Output: 5
  return 0;
}