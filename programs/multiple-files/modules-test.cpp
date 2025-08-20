#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

import library;

TEST_CASE("doubleValue") {
    CHECK(doubleValue(2) == 4);
    CHECK(doubleValue(-3) == -6);
    CHECK(doubleValue(0) == 0);
}