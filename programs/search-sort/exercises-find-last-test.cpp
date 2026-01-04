
 

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("findLast") {
    vector<int> vec = {5, 3, 7, 3, 2, 7, 9, 3};
    CHECK(findLast(vec, 3) == 7);
    CHECK(findLast(vec, 7) == 5);
    CHECK(findLast(vec, 5) == 0);
    CHECK(findLast(vec, 4) == -1);
}