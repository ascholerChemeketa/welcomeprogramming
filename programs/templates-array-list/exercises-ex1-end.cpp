#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("doubleIt with double") {
    double result = doubleIt(3.5);
    CHECK(result == 7.0);
}

TEST_CASE("doubleIt with string") {
    string s= "hello";
    string result = doubleIt(s);
    CHECK(result == "hellohello");
}
