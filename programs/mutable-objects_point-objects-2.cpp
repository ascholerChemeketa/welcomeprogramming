#include <iostream>
struct Point {
  double x, y;
};
int main() {
  Point* blank = nullptr;
  blank = new Point{3, 4};
  cout << blank->x << ", " << blank->y << endl;
  delete blank; // Important to release memory
  return 0;
}