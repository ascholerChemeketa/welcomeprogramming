
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("assignmentOperator") {
    NumberWrapper original(42);
    NumberWrapper copy(100);

    copy = original;
    CHECK(copy.getNum() == 42);

    copy.setNum(200);
    CHECK(original.getNum() == 42); // Original should remain unchanged
    CHECK(copy.getNum() == 200); // Copy should reflect the change
}

TEST_CASE("assignmentOperator self assignment") {
    NumberWrapper original(42);

    // self assignment... nothing should change
    original = original;

    CHECK(original.getNum() == 42);
}