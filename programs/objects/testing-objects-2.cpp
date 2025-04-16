#include <iostream>
using namespace std;

class Point {
public:
    Point(double x, double y) {
        m_x = x;
        m_y = y;
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


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Point Constructor - 2 args") {
    Point p1(3.0, 4.2);
    CHECK(p1.getX() == doctest::Approx(3.0));
    CHECK(p1.getY() == doctest::Approx(4.2));
}