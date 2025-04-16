#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    cout << "distance(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ")" << endl;
    double dx = x2 - x1;
    double dy = y2 - y1;
    cout << "dx is " << dx << endl;
    cout << "dy is " << dy << endl;
    return 0;  // Fixme!!!
}

// Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("distance") {
    CHECK(distance(0.0, 0.0, 2.0, 0.0) == doctest::Approx(2.0));
    CHECK(distance(1.0, 2.0, 4.0, 6.0) == doctest::Approx(5.0));
    CHECK(distance(-1.0, -2.0, 2.0, 1.0) == doctest::Approx(4.24264));
}