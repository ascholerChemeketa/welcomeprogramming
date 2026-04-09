
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Reader::readBook") {
    Book b1("Book 1", 100);
    Book b2("Book 2", 200);
    Reader r("Alice");
    r.readBook(b1);

    string expected = "Book 1";
    CHECK(r.getHistory() == expected);

    r.readBook(b2);
    expected = "Book 2";
    CHECK(r.getHistory() == expected);
}