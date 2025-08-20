#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

import DateFunctions;

using namespace std;

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

TEST_CASE("getDay") {
    CHECK(getDay("3/4/2023") == 4);
    CHECK(getDay("12/31/1999") == 31);
    CHECK(getDay("1/1/2001") == 1);
}

TEST_CASE("getDay invalid inputs") {
    CHECK_THROWS(getDay("3/431/2023/"));
    CHECK_THROWS(getDay("2/2023")); //only one slash
    CHECK_THROWS(getDay("3/1a/2023"));
}

TEST_CASE("getYear") {
    CHECK(getYear("3/4/2023") == 2023);
    CHECK(getYear("12/31/1999") == 1999);
    CHECK(getYear("1/1/2001") == 2001);
}

TEST_CASE("getYear invalid inputs") {
    CHECK_THROWS(getDay("2/2023")); //only one /
    CHECK_THROWS(getYear("3/4/20a23"));
    CHECK_THROWS(getYear("12/31/abcd"));
}

TEST_CASE("daysBeforeMonth") {
    CHECK(daysBeforeMonth(1) == 0);
    CHECK(daysBeforeMonth(2) == 31);
    CHECK(daysBeforeMonth(4) == 90);
    CHECK(daysBeforeMonth(12) == 334);
}

TEST_CASE("daysBeforeMonth invalid inputs") {
    CHECK_THROWS(daysBeforeMonth(0));
    CHECK_THROWS(daysBeforeMonth(13));
    CHECK_THROWS(daysBeforeMonth(-1));
}

TEST_CASE("dateToDays") {
    CHECK(dateToDays("1/1/0000") == 1);
    CHECK(dateToDays("4/10/0001") == (90 + 10 + 1 * 365));
    CHECK(dateToDays("3/14/2025") == (59 + 14 + 2025 * 365));
}