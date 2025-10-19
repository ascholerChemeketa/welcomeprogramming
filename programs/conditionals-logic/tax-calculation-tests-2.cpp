


// Bring in unit testing code and tell it to build a main function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// The tests
TEST_CASE("calculateTax") {
  CHECK(calculateTax(5000, false) == doctest::Approx(500));
  // CHECK(calculateTax(50000, false) == doctest::Approx(8000));
  // CHECK(calculateTax(120000, true) == doctest::Approx(21500));
}
