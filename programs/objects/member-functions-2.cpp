class Point {
public:
    ...
    // Method to get distance from 0,0
    double distanceToOrigin() {
        double x = getX();  //call getX on current point
        double y = getY();  //call getY on current point
        return sqrt(x * x + y * y);
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