
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("countMatches with int") {
    vector<int> numbers = {1, 2, 3, 2, 4, 2};
    int result = countMatches(numbers, 2);
    CHECK(result == 3);

    result = countMatches(numbers, 5);
    CHECK(result == 0);
}

TEST_CASE("countMatches with string") {
    vector<string> strings = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    string target = "apple";
    int result = countMatches(strings, target);
    CHECK(result == 3);

    target = "orange";
    result = countMatches(strings, target);
    CHECK(result == 0);
}
