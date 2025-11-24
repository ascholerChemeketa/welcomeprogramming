#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Given a string, count the number of times each letter appears
// and return those counts in a vector of integers.
// The vector at index 0 holds the count for 'a',
// index 1 holds the count for 'b', and so on.
vector<int> countLetters(const string& text) {
    // FIX ME - make and return a vector with 26 0's
}

// Given a vector of letter counts, print each count
void printLetterCounts(const vector<int>& counts) {
    for (size_t i = 0; i < counts.size(); ++i) {
        // add the index to 'a' to get a number, cast that as a character
        char curChar = static_cast<char>('a' + i);
        cout << curChar << ": " << counts.at(i) << endl;
    }
}

int main() {
    // R"(string)" is a raw string literal and can span multiple lines
    string testString = R"(
        This is a test string.
        It contains some text.
    )";

    vector<int> counts = countLetters(testString);

    printLetterCounts(counts);
}
