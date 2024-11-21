/* This function takes a Point object as input and prints its coordinates to the
 * console in the format (x, y). */
#include <iostream>

// Assuming Point structure exists. If not, define it.
struct Point {
  int x, y;
};

void printPoint(Point p) {
  cout << "(" << p.x << ", " << p.y << ")" << endl;
}