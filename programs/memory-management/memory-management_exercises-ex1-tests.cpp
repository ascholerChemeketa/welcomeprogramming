
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("getPI") {
    // Assuming getPI is defined in the included file
    double* pi = getPI();
    CHECK(*pi == doctest::Approx(3.14));
    delete pi;
}