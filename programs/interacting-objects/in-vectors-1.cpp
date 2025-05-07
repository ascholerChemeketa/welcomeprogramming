export module SimplePoint;

export class SimplePoint1 {
public:
    SimplePoint1(double x, double y) {
        m_x = x;
        m_y = y;
    }

    double getX() const {
        return m_x;
    }
private:
    double m_x, m_y;
};


export class SimplePoint2 {
public:
    SimplePoint2() {
        m_x = 0;
        m_y = 0;
    }
    SimplePoint2(double x, double y) {
        m_x = x;
        m_y = y;
    }

    double getX() const {
        return m_x;
    }
private:
    double m_x, m_y;
};