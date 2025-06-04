
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test postfix ++") {
    EvenNumber n1(2);
    n1++; // Increment n2 by 2, which should make it 4
    CHECK(n1.getValue() == 4);

    // Increment again
    // with postincrement, getValue should get the OLD value
    int initialValue = (n1++).getValue();
    CHECK(initialValue == 4);
    CHECK(n1.getValue() == 6);
}