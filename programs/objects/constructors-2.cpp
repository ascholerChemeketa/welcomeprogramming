#include <iostream>
using namespace std;

class Point {
public:
    Point() {
        //nothing to do, m_x and m_y are already initialized to 0
    }
    Point(double x, double y) {
        // change the default values
        m_x = x;
        m_y = y;
    }
private:
    double m_x = 0;
    double m_y = 0;
};

int main() {
    Point p1;
    Point p2(4, 5);
}