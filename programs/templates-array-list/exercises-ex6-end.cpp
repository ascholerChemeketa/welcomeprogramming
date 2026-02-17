}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("ArrayList removeAt") {
    ArrayList<int> list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    list.removeAt(1); // Remove element at index 1 (value 20)
    CHECK(list.size() == 3);
    CHECK(list.get(0) == 10);
    CHECK(list.get(1) == 30);
    CHECK(list.get(2) == 40);
}

