

private:
    Point m_start;
    Point m_end;
};


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Segment::getEnd") {
    Segment s1(Point(0, 0), Point(3, 4));

    CHECK(s1.getEnd().getX() == doctest::Approx(3));
    CHECK(s1.getEnd().getY() == doctest::Approx(4));
}