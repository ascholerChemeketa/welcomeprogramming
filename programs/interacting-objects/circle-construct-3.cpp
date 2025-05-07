class Point {
public:
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    }

private:
    double m_x;
    double m_y;
};

class Circle {
public:
    Circle(double radius, double x, double y): m_center(x, y) {
        m_radius = radius;
    }

    // Explicitly say to initialized m_center with (0, 0)
    Circle(double radius): m_center(0, 0) {
        m_radius = radius;
    }

    Circle(double radius, const Point& p): m_center(p) {
        m_radius = radius;
    }

private:
    double m_radius;
    Point m_center;
};

int main() {
    Circle c1(5.0, 2, 1);

    // Use the second constructor
    Point p1(3.2, 2.0);
    Circle c2(5.0, p1);

    // Use the second constructor with a nameless Point object
    Circle c3(5.0, Point(3.2, 2.0));

    // Use the radius-only constructor
    Circle c4(5.0);
};