// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test letterCount") {
    int n0 = letterCount("", 'e');
    CHECK(n0 == 0);

    int n1 = letterCount("e", 'e');
    CHECK(n1 == 1);

    int n2 = letterCount("hello", 'e');
    CHECK(n2 == 1);

    int n3 = letterCount("hello", 'l');
    CHECK(n3 == 2);

    int n4 = letterCount("hello there", 'e');
    CHECK(n4 == 3);

    int n5 = letterCount("hello there", 'q');
    CHECK(n5 == 0);
}