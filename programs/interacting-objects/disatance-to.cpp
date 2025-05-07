double Point::distanceTo(const Point& other) const {
    double xdiff = other.m_x - m_x;
    double ydiff = other.m_y - m_y;
    double distance = sqrt(xdiff * xdiff + ydiff * ydiff);
    return distance;
}