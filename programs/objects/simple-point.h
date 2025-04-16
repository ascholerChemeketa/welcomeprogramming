// Header guard
#ifndef SIMPLE_POINT_H
#define SIMPLE_POINT_H

// Include any libraries that are referenced here in the .h
// such as <string>

/**
 * @brief Represents a point in 2D space.
 * 
 */
class Point {
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

#endif // SIMPLE_POINT_H