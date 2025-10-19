

// Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// The tests
TEST_CASE("isPrime") {
    CHECK(isPrime(3) == true);
    CHECK(isPrime(7) == true);
    CHECK(isPrime(17) == true);
    CHECK(isPrime(4) == false);
    CHECK(isPrime(15) == false);
    // special cases
    CHECK(isPrime(1) == false);
    CHECK(isPrime(2) == true);
}
