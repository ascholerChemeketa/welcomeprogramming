// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test invest") {
    double i1 = investment(10000, 5, 0);
    CHECK(i1 == doctest::Approx(10000));

    double i2 = investment(10000, 5, 1);
    CHECK(i2 == doctest::Approx(10500));

    double i3 = investment(10000, 5, 2);
    CHECK(i3 == doctest::Approx(11025));

    double i4 = investment(10000, 5, 3);
    CHECK(i4 == doctest::Approx(11576.25).epsilon(0.01));

    double i5 = investment(5000, 10, 8);
    CHECK(i5 == doctest::Approx(10717.94).epsilon(0.01));
}