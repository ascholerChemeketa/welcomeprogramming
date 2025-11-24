#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    // R"(string)" is a raw string literal and can span multiple lines
    string testString = R"(
        This is a test string.
        It contains some text.
    )";

    vector<int> counts(26, 0);

    for (char c : testString) {
        char lower = static_cast<char>( tolower(c) );
        if ( isalpha(lower) ) {
            int index = lower - 'a';
            int currentCount = counts.at(index);
            counts.at(index) = currentCount + 1;
        }
    }

    for (size_t i = 0; i < counts.size(); ++i) {
        // add the index to 'a' to get a number, cast that as a character
        char curChar = static_cast<char>('a' + i);
        cout << curChar << ": " << counts.at(i) << endl;
    }
}
