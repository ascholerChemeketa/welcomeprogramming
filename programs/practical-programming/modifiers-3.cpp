#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> words = {"one", "two", "three", "four", "five", "six"};

    transform(
      words.begin(),
      words.end(),
      words.begin(),
      [](string word) {
          word.at(0) = toupper(word.at(0));
          return word;
      }
    );

    cout << "Words with first letter capitalized: ";
    for (const auto& word : words) {
        cout << word << " ";
    }
}