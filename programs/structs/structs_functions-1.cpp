#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point origin = { 0.0, 0.0 };
    Point point = { 3.0, 4.0 };
    cout << "The distance from the point to the origin is "
         << distance (origin, point) << endl;
}