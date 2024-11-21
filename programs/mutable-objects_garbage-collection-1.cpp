/* This code snippet creates a Point object named blank and initializes it with
 * coordinates (3, 4). It then sets blank to null, effectively releasing the
 * object's memory (in languages with garbage collection). In C++, you would
 * typically use a smart pointer to manage the memory automatically. */
#include <iostream>

// Assuming Point structure exists. If not, define it.
struct Point {
  int x, y;
};

int main() {
  Point* blank = new Point{3, 4};
  cout << blank->x << ", " << blank->y << endl;
  delete blank;    // Manually release memory
  blank = nullptr; // Set to null
  return 0;
}