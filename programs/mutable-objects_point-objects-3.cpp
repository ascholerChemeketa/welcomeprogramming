#include <iostream>
struct Point {
  int x, y;
};
int main() {
  Point blank = {10, 20}; // Example Point
  int x = blank.x;
  cout << x << endl; // prints 10
  return 0;
}