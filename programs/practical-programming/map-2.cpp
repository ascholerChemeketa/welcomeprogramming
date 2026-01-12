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
  for ( auto it = wordCounts.begin(); it != wordCounts.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
    // // Longer version without using -> operator
    // pair<string, int> p = *it;
    // cout << p.first << ": " << p.second << endl;
  }
}

