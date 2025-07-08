// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test numLegs") {
    int n1 = numLegs({'c'});
    CHECK(n1 == 4);

    int n2 = numLegs({'d'});
    CHECK(n2 == 2);

    int n3 = numLegs({'c', 'd'});
    CHECK(n3 == 6);

    int n4 = numLegs({'c', 'd', 'd', 'c', 'c', 'c'});
    CHECK(n4 == 20);

    int n5 = numLegs({'d', 'd', 'c', 'c', 'c', 'd', 'd', 'd', 'd'});
    CHECK(n5 == 24);

    int n6 = numLegs({});
    CHECK(n6 == 0);
}