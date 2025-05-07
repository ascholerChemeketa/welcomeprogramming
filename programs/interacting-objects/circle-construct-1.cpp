class Point {
public:
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    }

    Point() {
        m_x = 0;
        m_y = 0;
    }

private:
    double m_x;
    double m_y;
};

class Circle {
public:
    Circle(double radius, double x, double y) {
        m_radius = radius;
        Point p(x, y); // Create a Point object
        // Copy that Point into m_center
        m_center = p;
    }

private:
    double m_radius;
    Point m_center;
};

int main() {
    Circle c1(5.0, 2, 1);
};