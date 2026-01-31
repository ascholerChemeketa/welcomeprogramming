
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("assignmentOperator") {
    NumberWrapper original(6, 7);
    NumberWrapper copy(100, 101);

    copy = original;
    CHECK(copy.getNumOne() == 6);
    CHECK(copy.getNumTwo() == 7);

    copy.setNum(0, 200);
    CHECK(original.getNumOne() == 6); // Original should remain unchanged
    CHECK(original.getNumTwo() == 7);
    CHECK(copy.getNumOne() == 200); // Copy should reflect the change
}

TEST_CASE("assignmentOperator self assignment") {
    NumberWrapper original(42, 43);
    // self assignment... nothing should change
    original = original;

    CHECK(original.getNumOne() == 42);
    CHECK(original.getNumTwo() == 43);
}