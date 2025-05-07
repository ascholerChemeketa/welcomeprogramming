

// We are cheating here by making the points public
// This is just so the test code can access them
// without you adding getters
public:
    Point m_start;
    Point m_end;
};


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Segment:: alternative constructor") {
    Point p1(0, 0);
    Point p2(3, 4);
    Segment s1(p1, p2);

    CHECK(s1.m_start.getX() == doctest::Approx(0));
    CHECK(s1.m_start.getY() == doctest::Approx(0));
    CHECK(s1.m_end.getX() == doctest::Approx(3));
    CHECK(s1.m_end.getY() == doctest::Approx(4));

    Segment s2(Point(5, 6), Point(7, 8));
    CHECK(s2.m_start.getX() == doctest::Approx(5));
    CHECK(s2.m_start.getY() == doctest::Approx(6));
    CHECK(s2.m_end.getX() == doctest::Approx(7));
    CHECK(s2.m_end.getY() == doctest::Approx(8));
}