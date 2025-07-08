// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test power") {
    int n1 = power(20, 0);
    CHECK(n1 == 1);

    int n2 = power(8, 1);
    CHECK(n2 == 8);

    int n3 = power(5, 2);
    CHECK(n3 == 25);

    int n4 = power(3, 5);
    CHECK(n4 == 243);

    int n5 = power(2, 20);
    CHECK(n5 == 1048576);
}