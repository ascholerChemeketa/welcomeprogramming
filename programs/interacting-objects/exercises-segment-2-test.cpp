

// We are cheating here by making the points public
// This is just so the test code can access them
// without you adding getters
public:
    Point m_start;
    Point m_end;
};


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Segment:: 4-arg constructor") {
    Segment s1(0, 0, 3, 4);

    CHECK(s1.m_start.getX() == doctest::Approx(0));
    CHECK(s1.m_start.getY() == doctest::Approx(0));
    CHECK(s1.m_end.getX() == doctest::Approx(3));
    CHECK(s1.m_end.getY() == doctest::Approx(4));
}