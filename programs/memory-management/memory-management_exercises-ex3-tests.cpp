
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("makeBigArray") {
    double* arr = makeBigArray();
    for(int i = 0; i < 100; ++i) {
        CHECK(arr[i] == doctest::Approx(5.0));
    }
    delete[] arr;
}