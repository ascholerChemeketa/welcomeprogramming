
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


// Test data. Global scope is used to avoid declaring data in each test case.
// Data is marked const to avoid accidental changes.

const Answers KEY1 = {'A', 'B', 'C', 'D', 'E'};
const Answers KEY2 = {'A', 'C', 'C', 'D', 'B'};

const ResponseSet RESPONSES1 = {
    {'A', 'C', 'B', 'D', 'B'},
    {'C', 'C', 'C', 'C', 'C'},
    {'A', 'C', 'C', 'D', 'B'},
    {'B', 'C', '_', 'D', 'B'}
};

void printVector(const string& label, const vector<int>& vec) {
    cout << label << ": ";
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

TEST_CASE("studentScores") {
    // Test with key 1
    vector<int> expected1 = {2, 1, 3, 1};
    vector<int> studentScores1 = studentScores(RESPONSES1, KEY1);
    printVector("studentScores1", studentScores1);
    printVector("Expected", expected1);
    CHECK(studentScores1 == expected1);

    // Test with key 2
    vector<int> expected2 = {4, 2, 5, 3};
    vector<int> studentScores2 = studentScores(RESPONSES1, KEY2);
    printVector("studentScores2", studentScores2);
    printVector("Expected", expected2);
    CHECK(studentScores2 == expected2);
}