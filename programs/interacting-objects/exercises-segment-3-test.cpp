

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Segment::minX") {
    Segment s1(Point(0, 0), Point(3, 4));
    CHECK(s1.minX() == doctest::Approx(0));

    Segment s2(Point(3, 4), Point(0, 0));
    CHECK(s2.minX() == doctest::Approx(0));

    Segment s3(Point(-3, 4), Point(0, 0));
    CHECK(s3.minX() == doctest::Approx(-3));
}