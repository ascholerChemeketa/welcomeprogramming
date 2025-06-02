#include <iostream>

using namespace std;

class TwoDPoint {
private:
  int m_x;
  int m_y;

public:
  TwoDPoint(int xLocation, int yLocation) {
      m_x = xLocation;
      m_y = yLocation;
  }
  string toString() const {
      return  to_string(m_x) + ", " + to_string(m_y);
  }
};
