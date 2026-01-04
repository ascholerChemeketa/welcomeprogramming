


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("descendingQuickSort") {
    vector<int> test = {1, 3, 2, 5, 4, 8, 7, 6};
    vector<int> temp(test.size());

    descendingQuickSort(test, 0, 7);
    string debug1 = "After sort: " + vectorToString(test);
    vector<int> expected1 = {8, 7, 6, 5, 4, 3, 2, 1};
    INFO(debug1);
    INFO("Expected: ", vectorToString(expected1));
    CHECK(test == expected1);
}

TEST_CASE("descendingQuickSortPartial") {
    vector<int> test = {0, 0, 7, 5, 4, 3, 2, 1, 8, 6, 0, 0};
    vector<int> temp(test.size());

    descendingQuickSort(test, 2, 9);
    string debug1 = "After sort: " + vectorToString(test);
    vector<int> expected1 = {0, 0, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};
    INFO(debug1);
    INFO("Expected: ", vectorToString(expected1));
    CHECK(test == expected1);
}