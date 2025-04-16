// Start global module fragment
module;

// All includes go here
#include <cmath>

// Start module, declare its name and make available outside this module
export module Point;

/**
 * @brief Represents a point in 2D space.
 *
 */
export class Point {
public:
  /**
   * @brief Construct a new Point object
   *
   * @param x starting x coordinate
   * @param y starting y coordinate
   */
  Point(double x, double y);

  /**
   * @brief Get the x coordinate of the point
   *
   * @return double x coordinate
   */
  double getX();

private:
  double m_x;
  double m_y;
};

// Implementations
Point::Point(double x, double y)
{
  m_x = x;
  m_y = y;
}

double Point::getX()
{
  return m_x;
}