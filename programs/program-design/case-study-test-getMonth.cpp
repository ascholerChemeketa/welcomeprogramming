#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

import DateFunctions;

TEST_CASE("getMonth") {
    CHECK(getMonth("3/4/2023") == 3);
    CHECK(getMonth("12/31/1999") == 12);
    CHECK(getMonth("1/1/2001") == 1);
}

TEST_CASE("getMonth invalid inputs") {
    CHECK_THROWS(getMonth("13/1/2023"));
    CHECK_THROWS(getMonth("abc/1/2023"));
    CHECK_THROWS(getMonth("1a5/1/2023"));
}