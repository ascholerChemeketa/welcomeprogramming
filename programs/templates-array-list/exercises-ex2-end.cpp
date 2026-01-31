#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("sumList with double") {
    vector<double> numbers = {1.5, 2.5, 3.0};
    double result = sumList(numbers);
    CHECK(result == doctest::Approx(7.0));
}

TEST_CASE("sumList with string") {
    vector<string> strings = {"hello", " ", "world", "!"};
    string result = sumList(strings);
    CHECK(result == "hello world!");
}
