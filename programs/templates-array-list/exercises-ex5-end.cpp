

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("ItemCounter") {
    string s1 = "hello";
    ItemCounter<string> list(s1);
    CHECK(list.getItem() == s1);
    CHECK(list.getCount() == 0);
    list.increment();
    CHECK(list.getCount() == 1);
    list.increment();
    CHECK(list.getCount() == 2);
}

