// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test investmentLength") {
    int n1 = investmentLength(10000, 10000, 8);
    CHECK(n1 == 0);

    int n2 = investmentLength(10000, 10001, 8);
    CHECK(n2 == 1);

    int n3 = investmentLength(10000, 11000, 5);
    CHECK(n3 == 2);

    int n4 = investmentLength(10000, 20000, 10);
    CHECK(n4 == 8);

    int n5 = investmentLength(50, 20000, 4);
    CHECK(n5 == 153);
}