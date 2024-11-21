/* This main function demonstrates the use of the riddle function. It
 * initializes an integer x and a Point object blank. It then calls riddle with
 * x and blank, prints the result, and then prints the values of x, blank.x, and
 * blank.y to show that the original values are not modified. */
#include <iostream>

// Assuming Point structure exists. If not, define it.
struct Point {
  int x, y;
};

int riddle(int x, Point p) {
  x = x + 7;
  return x + p.x + p.y;
}

int main() {
  int x = 5;
  Point blank = {1, 2};
  cout << riddle(x, blank) << endl; // Example usage
  cout << x << endl;
  cout << blank.x << endl;
  cout << blank.y << endl;
  return 0;
}