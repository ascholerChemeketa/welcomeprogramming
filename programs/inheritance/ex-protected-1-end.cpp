
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test VerySilly") {
    VerySilly v1(4, "five", 6.1);
    string data = v1.toString();
    CHECK(data == "4 five 6.100000");
}
