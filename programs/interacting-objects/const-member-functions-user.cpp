// the code above is included here...

double distanceBetween(const Point& p1, const Point& p2) {
    double xdiff = p2.getX() - p1.getX();
    double ydiff = p2.getY() - p1.getY();
    double distance = sqrt(xdiff * xdiff + ydiff * ydiff);
}

int main() {
    Point p1(0.0, 0.0);
    Point p2(6.0, 8.0);
    double distance = distanceBetween(p1, p2);
}
