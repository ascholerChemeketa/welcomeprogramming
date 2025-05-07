

// We are cheating here by making the points public
// This is just so the test code can access them
// without you adding getters
public:
    Point m_start;
    Point m_end;
};


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Segment::moveBy") {
    Segment s1(Point(0, 0), Point(3, 4));
    s1.moveBy(2, -3);

    CHECK(s1.m_start.getX() == doctest::Approx(2));
    CHECK(s1.m_start.getY() == doctest::Approx(-3));
    CHECK(s1.m_end.getX() == doctest::Approx(5));
    CHECK(s1.m_end.getY() == doctest::Approx(1));
}