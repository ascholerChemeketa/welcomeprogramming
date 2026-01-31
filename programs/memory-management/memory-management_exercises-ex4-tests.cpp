
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("copyConstructor") {
    NumberWrapper original(6, 7);
    NumberWrapper copy(original);

    CHECK(copy.getNumOne() == 6);
    CHECK(copy.getNumTwo() == 7);
    
    copy.setNum(0,100);
    CHECK(original.getNumOne() == 6); // Original should remain unchanged
    CHECK(original.getNumTwo() == 7);
    CHECK(copy.getNumOne() == 100); // Copy should reflect the change
}