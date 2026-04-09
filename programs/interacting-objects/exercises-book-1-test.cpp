
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Book::isLonger") {
    Book b1("Book 1", 100);
    Book b2("Book 2", 200);

    CHECK(b1.isLonger(b2) == false);
    CHECK(b2.isLonger(b1) == true);

    Book b3("Book 3", 200);
    CHECK(b3.isLonger(b2) == false);
    CHECK(b2.isLonger(b3) == false);
}