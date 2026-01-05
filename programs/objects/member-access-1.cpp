#include <iostream>
using namespace std;
class Point {
public:
    double getX() {
        return m_x;
    }

    void setX(double x) {
        m_x = x;
    }

private:
    double m_x;
    double m_y;
};

int main() {
    Point p1;
    p1.setX(5.0);
    cout << "Point 1's x after setX: " << p1.getX() << endl;
    p1.setX(12.0);
    cout << "Point 1's x after setX: " << p1.getX() << endl;
}