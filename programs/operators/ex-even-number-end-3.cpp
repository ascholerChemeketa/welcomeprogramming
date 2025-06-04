
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test prefix ++") {
    EvenNumber n1(2);
    ++n1; // Increment n2 by 2, which should make it 4
    CHECK(n1.getValue() == 4);

    // Increment again
    // with preincrement, getValue should get the new value
    int initialValue = (++n1).getValue();
    CHECK(initialValue == 6);
    CHECK(n1.getValue() == 6);
}