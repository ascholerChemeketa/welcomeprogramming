
// re-enable looping constructs
#undef for
#undef while
#undef goto

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("binarySearchSteps") {
    vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int start = 0;
    int end = vec.size() - 1;
    // Test searching for existing elements
    CHECK(binarySearchSteps(vec, 9, start, end) == 1);
    CHECK(binarySearchSteps(vec, 3, start, end) == 2);
    CHECK(binarySearchSteps(vec, 15, start, end) == 2);
    CHECK(binarySearchSteps(vec, 11, start, end) == 3);
    CHECK(binarySearchSteps(vec, 19, start, end) == 4);
    // Test searching for non-existing elements
    CHECK(binarySearchSteps(vec, 2, start, end) == 3);
    CHECK(binarySearchSteps(vec, 2, start, end) == 3);
    CHECK(binarySearchSteps(vec, 12, start, end) == 4);
}