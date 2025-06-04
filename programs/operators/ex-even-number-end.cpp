
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test ==") {
    EvenNumber n1(6);
    EvenNumber n2(6);
    EvenNumber n3(8);

    CHECK(n1 == n2);
    CHECK(n1 != n3);
}