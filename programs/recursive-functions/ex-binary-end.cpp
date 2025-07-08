// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test binary") {
    string s1 = makeBinary(1);
    CHECK(s1 == "1");

    string s2 = makeBinary(2);
    CHECK(s2 == "10");

    string s3 = makeBinary(3);
    CHECK(s3 == "11");

    string s5 = makeBinary(5);
    CHECK(s5 == "101");

    string s6 = makeBinary(13);
    CHECK(s6 == "1101");

    string s7 = makeBinary(47);
    CHECK(s7 == "101111");

    string s8 = makeBinary(254);
    CHECK(s8 == "11111110");
}