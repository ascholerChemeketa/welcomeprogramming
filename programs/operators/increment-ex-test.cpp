
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test --") {
    Rational r1(5, 2); // Represents 5/2
    --r1;
    CHECK(r1.toString() == "3/2"); // After pre-decrement, should be 3/2
    Rational r2 = --r1;
    CHECK(r1.toString() == "1/2");
    CHECK(r2.toString() == "1/2");
}
