/*This function takes a Rectangle and two integers as input, representing
 * changes in x and y coordinates. It modifies the rectangle's position by
 * adding dx to its x coordinate and dy to its y coordinate.*/
#include <iostream>
struct Rectangle {
  double x, y, width, height;
};
void moveRect(Rectangle& box, double dx, double dy) {
  box.x = box.x + dx;
  box.y = box.y + dy;
}