
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Point3D") {
    ThreeDPoint p1(1, 2, 3);
    string data = p1.toString();
    CHECK(data == "1, 2, 3");

    TwoDPoint p2 = p1;  //copy just the x/y into a 2D point
    string data2 = p2.toString();
    CHECK(data2 == "1, 2");

    ThreeDPoint p3(0, 0, 0);
    string data3 = p3.toString();
    CHECK(data3 == "0, 0, 0");
}
