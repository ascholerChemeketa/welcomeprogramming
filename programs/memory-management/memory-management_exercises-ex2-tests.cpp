
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("makeArray") {
    double* arr = makeArray();
    CHECK(arr[0] == doctest::Approx(1.1));
    CHECK(arr[1] == doctest::Approx(2.2));
    CHECK(arr[2] == doctest::Approx(3.3));
    delete[] arr;
}