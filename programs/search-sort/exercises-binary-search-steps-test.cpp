
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("binarySearchSteps") {
    vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    // Test searching for existing elements
    CHECK(binarySearchSteps(vec, 9) == 1);
    CHECK(binarySearchSteps(vec, 3) == 2);
    CHECK(binarySearchSteps(vec, 15) == 2);
    CHECK(binarySearchSteps(vec, 11) == 3);
    CHECK(binarySearchSteps(vec, 19) == 4);
    // Test searching for non-existing elements
    CHECK(binarySearchSteps(vec, 2) == 3);
    CHECK(binarySearchSteps(vec, 2) == 3);
    CHECK(binarySearchSteps(vec, 12) == 4);
}