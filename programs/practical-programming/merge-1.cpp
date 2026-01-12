#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> words = {"a", "stitch", "in", "time", "saves", "nine"};

    auto it = max_element(words.begin(), words.end());
    cout << "Max word alphabetically: " << *it << endl;

    // Custom comparator to find the longest word
    auto longestIt = max_element(
        words.begin(),
        words.end(),
        // Lambda function to compare by length
        [](const string& a, const string& b) {
            return a.length() < b.length();
        }
    );

    cout << "Longest word: " << *longestIt << endl;
}