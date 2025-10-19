
// Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// The tests
TEST_CASE("countPrimes") {
    CHECK(countPrimes(2) == 1);
    CHECK(countPrimes(4) == 2);
    CHECK(countPrimes(10) == 4);
    CHECK(countPrimes(11) == 4);
    CHECK(countPrimes(100) == 25);
}
