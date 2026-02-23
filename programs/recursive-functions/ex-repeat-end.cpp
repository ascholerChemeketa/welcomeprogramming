// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test repeat") {
    string r1 = repeat("hello", 0);
    CHECK(r1 == "");
    string r2 = repeat("hello", 1);
    CHECK(r2 == "hello");
    string r3 = repeat("hello", 2);
    CHECK(r3 == "hellohello");

    string f4 = repeat("bye", 5);
    CHECK(f4 == "byebyebyebyebye");
}