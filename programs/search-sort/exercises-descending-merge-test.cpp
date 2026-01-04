


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("descendingMerge") {
    vector<int> test = {8, 7, 3, 1, 6, 5, 4, 2};
    vector<int> temp(test.size());

    descendingMerge(test, temp, 0, 3, 7);
    string debug1 = "After merge: " + vectorToString(test);
    vector<int> expected1 = {8, 7, 6, 5, 4, 3, 2, 1};
    INFO(debug1);
    INFO("Expected: ", vectorToString(expected1));
    CHECK(test == expected1);
}

TEST_CASE("descendingMergeDifferentSizes") {
    vector<int> test = {7, 5, 4, 3, 2, 1, 8, 6};
    vector<int> temp(test.size());

    descendingMerge(test, temp, 0, 5, 7);
    string debug1 = "After merge: " + vectorToString(test);
    vector<int> expected1 = {8, 7, 6, 5, 4, 3, 2, 1};
    INFO(debug1);
    INFO("Expected: ", vectorToString(expected1));
    CHECK(test == expected1);
}

TEST_CASE("descendingMergePartial") {
    vector<int> test = {0, 0, 7, 5, 4, 3, 2, 1, 8, 6, 0, 0};
    vector<int> temp(test.size());

    descendingMerge(test, temp, 2, 7, 9);
    string debug1 = "After merge: " + vectorToString(test);
    vector<int> expected1 = {0, 0, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};
    INFO(debug1);
    INFO("Expected: ", vectorToString(expected1));
    CHECK(test == expected1);
}