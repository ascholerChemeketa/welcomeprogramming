// Include <cmath> or any other needed libraries

// Include the header file for the Point class
#include "Point.h"

// possibly use using namespace std;

Point::Point(double x, double y) {
  m_x = x;
  m_y = y;
}

double Point::getX() {
  return m_x;
}