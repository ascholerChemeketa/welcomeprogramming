
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("ItemCounter with strings") {
    ItemCounter<string> counter;
    counter.item = "apple";
    counter.count = 5;
    CHECK(counter.item == "apple");
    CHECK(counter.count == 5);
}

struct Person {
    string name;
    int age;

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

TEST_CASE("ItemCounter with Person") {
    ItemCounter<Person> counter;
    counter.item = {"Bob", 30};
    counter.count = 2;
    CHECK(counter.item == (Person{"Bob", 30}));
    CHECK(counter.count == 2);
}
