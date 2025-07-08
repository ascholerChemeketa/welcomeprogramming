// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test power") {
    int n1 = getMax({10});
    CHECK(n1 == 10);

    int n2 = getMax({10, 20});
    CHECK(n2 == 20);

    int n3 = getMax({10, 20, 5});
    CHECK(n3 == 20);

    int n4 = getMax({10, 20, 30, 5});
    CHECK(n4 == 30);

    int n5 = getMax({40, 20, 30, 10, 5});
    CHECK(n5 == 40);

    int n6 = getMax({40, 20, 30, 10, 45});
    CHECK(n6 == 45);
}