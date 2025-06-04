
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test <") {
    Person p1("Anna", "Smith");
    Person p2("Christian", "Garcia");
    Person p3("Charles", "Johnson");
    Person p4("Becca", "Johnson");
    Person p5("Dave", "Garcia");
    CHECK(p2 < p1); // Christian Garcia < Anna Smith
    CHECK(p2 < p4); // Christian Garcia < Becca Johnson
    CHECK(p2 < p5); // Christian Garcia < Dave Garcia
    CHECK(p4 < p3); // Becca Johnson < Charles Johnson

    // Now show off sort in action
    cout << "Sorted people:" << endl;
    vector<Person> people = {p1, p2, p3, p4, p5};
    sort(people.begin(), people.end());
    for (const Person& person : people) {
        cout << person.toString() << endl;
    }
}
