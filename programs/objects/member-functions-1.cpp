class Point {
public:
    ...
    // Method to get distance from 0,0
    double distanceToOrigin() {
        return sqrt(m_x * m_x + m_y * m_y);
    }

    double getX() {
        return m_x;
    }
    
    double getY() {
        return m_y;
    }

private:
    double m_x, m_y;
};
