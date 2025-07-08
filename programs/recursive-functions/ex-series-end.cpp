// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test series") {
    double n1 = series(1);
    CHECK(n1 == doctest::Approx(1));

    double n2 = series(2);
    CHECK(n2 == doctest::Approx(1.5));

    double n3 = series(3);
    CHECK(n3 == doctest::Approx(1.75));

    double n4 = series(4);
    CHECK(n4 == doctest::Approx(1.875));

    double n5 = series(1000);
    CHECK(n5 == doctest::Approx(2));
}