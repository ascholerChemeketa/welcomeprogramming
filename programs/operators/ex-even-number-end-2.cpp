
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test +") {
    EvenNumber n1(6);
    EvenNumber n2(2);

    EvenNumber n3 = n1 + n2;

    CHECK(n3.getValue() == 8);
}