
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Dog") {
    Dog d1;
    string type = d1.getTypeString();
    CHECK(type == "Canine");

    //Make sure it is an Animal...
    //Trying to copy into a Animal only works if we have inherited
    Animal a1 = d1;
    bool isAnimal = a1.isOrganism();
    CHECK(isAnimal == true);
}