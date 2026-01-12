#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map to hold word counts
    map<string, int> wordCounts;
    wordCounts.insert({"apple", 4});
    wordCounts.insert({"banana", 2});
    wordCounts.insert({"orange", 5});

    // Access and display counts
    for (const pair<const string, int>& p : wordCounts) {
        cout << p.first << ": " << p.second << endl;
    }

    // Or, using auto
    cout << "Using auto:" << endl;
    for (const auto& p : wordCounts) {
        cout << p.first << ": " << p.second << endl;
    }
}

