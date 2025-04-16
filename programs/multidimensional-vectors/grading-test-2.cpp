
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


// Test data. Global scope is used to avoid declaring data in each test case.
// Data is marked const to avoid accidental changes.

const Answers KEY = {'A', 'C', 'C', 'D', 'B'};

const ResponseSet RESPONSES = {
    {'A', 'C', 'B', 'D', 'B'},
    {'C', 'C', 'C', 'C', 'C'},
    {'A', 'C', 'C', 'D', 'B'},
    {'B', 'C', '_', 'D', 'B'}
};

TEST_CASE("questionDifficulty") {
    // Check difficulty of first question
    double difficulty0 = questionDifficulty(RESPONSES, KEY, 0);
    CHECK(difficulty0 == doctest::Approx(0.5));

    // Check difficulty of second question
    double difficulty1 = questionDifficulty(RESPONSES, KEY, 1);
    CHECK(difficulty1 == doctest::Approx(1.0));
}