
};  //end of struct Person

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Set of Person ordered by age") {
    set<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

    auto it = people.begin();
    CHECK(it->name == "Bob");
    ++it;
    CHECK(it->name == "Alice");
    ++it;
    CHECK(it->name == "Charlie");
}
