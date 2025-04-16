/**
 * @brief Represents a point in 2D space.
 *
 * A longer description can go here, explaining the purpose of the class.
 */
class Point {
public:
    /**
     * @brief Construct a new Point object
     * 
     * @param x starting x coordinate
     * @param y starting y coordinate
     */
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    }

    /**
     * @brief Get the y coordinate of the point
     * 
     * @return double y coordinate
     */
    double getX() {
        return m_x;
    }

    /**
     * @brief Change the location of the point by dx and dy
     * 
     * @param dx change in x coordinate
     * @param dy change in y coordinate
     */
    void shift(double dx, double dy) {
        m_x += dx;
        m_y += dy;
    }
private:
    /// @brief x coordinate of the point. Measured in cm
    double m_x
    /// @brief y coordinate of the point. Measured in cm
    double m_y;
};