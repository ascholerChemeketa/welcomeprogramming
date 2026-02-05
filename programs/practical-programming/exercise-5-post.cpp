
} // end of sortItems

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test sortItems function") {
    vector<Item> items = {
        {"Apple", 1.20},
        {"Banana", 0.50},
        {"Orange", 0.80},
        {"Grapes", 2.00}
    };

    sortItems(items);

    REQUIRE(items.at(0).name == "Banana");
    REQUIRE(items.at(1).name == "Orange");
    REQUIRE(items.at(2).name == "Apple");
    REQUIRE(items.at(3).name == "Grapes");
}
