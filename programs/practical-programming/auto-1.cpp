#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;


int main() {
    list<string> fruit = {"apple", "date", "banana", "cherry"};

    // Create an iterator "it" that points to the beginning of the list
    // Continue until the end is reached
    // Use ++ to advance the iterator
    for (auto it = fruit.begin(); it != fruit.end(); ++it) {
        // Use *it to get the value
        cout << *it << endl;
    }
}