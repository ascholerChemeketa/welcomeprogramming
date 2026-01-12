#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> words = {"a", "stitch", "in", "time", "saves", "nine"};

    // Empty vector to hold longer words
    vector<string> longerWords;

    // Copy words longer than 3 characters using a lambda function
    // use back_inserter to add to the end of longerWords
    copy_if(
      words.begin(),
      words.end(),
      back_inserter(longerWords),
      [](const string& word) { return word.length() > 3; }
    );

    cout << "Longer words: ";
    for (const auto& word : longerWords) {
        cout << word << " ";
    }
}