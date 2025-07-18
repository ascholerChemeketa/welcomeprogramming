
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("copyConstructor") {
    NumberWrapper original(42);
    NumberWrapper copy(original);

    CHECK(copy.getNum() == 42);
    
    copy.setNum(100);
    CHECK(original.getNum() == 42); // Original should remain unchanged
    CHECK(copy.getNum() == 100); // Copy should reflect the change
}