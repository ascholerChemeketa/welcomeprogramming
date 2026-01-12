#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Create a map to hold word counts
    unordered_map<string, int> wordCounts;
    wordCounts.insert({"apple", 4});
    wordCounts.insert({"date", 2});
    wordCounts.insert({"orange", 5});
    wordCounts.insert({"banana", 2});

    // Alternative using structured bindings
    for (const auto& [word, count] : wordCounts) {
        cout << word << ": " << count << endl;
    }
}
