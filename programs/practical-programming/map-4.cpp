#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map to hold word counts
    map<string, int> wordCounts;
    wordCounts.insert({"apple", 4});
    wordCounts.insert({"orange", 5});
    wordCounts.insert({"banana", 2});

    // Alternative using structured bindings
    for (const auto& [word, count] : wordCounts) {
        cout << word << ": " << count << endl;
    }
}
