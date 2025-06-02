
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Point3D") {
    ThreeDPoint p1(1, 2, 3);
    //Only checking x/y
    string data = p1.toString();
    CHECK(data == "1, 2");

    TwoDPoint p2 = p1;  //copy just the x/y into a 2D point
    string data2 = p2.toString();
    CHECK(data2 == "1, 2");
}