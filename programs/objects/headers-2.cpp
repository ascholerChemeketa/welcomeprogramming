
#include <iostream>
using namespace std;

class Point {
public:
    // declare the constructor and a function
    Point(double x, double y);
    double getX();
private:
    double m_x;
    double m_y;
};

// Define the member functions using the scope resolution operator
Point::Point(double x, double y) {
    m_x = x;
    m_y = y;
}
double Point::getX() {
    return m_x;
}

int main() {
    Point p1(3, 4);
    cout << p1.getX();
}