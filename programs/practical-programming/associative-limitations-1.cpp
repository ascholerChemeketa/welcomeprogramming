#include <iostream>
#include <set>
#include <string>
using namespace std;


int main() {
    // Create a set of strings
    set<string> fruit = {"apple", "date", "banana", "cherry"};

    // // This would not compile:
    //cout << fruit.at(2) << endl;

    // // Nor would this:
    //set<string>::iterator it = fruit.begin() + 2;

    // Make an iterator that points to the beginning of the set
    set<string>::iterator it = fruit.begin();
    ++it; // now at 2nd element
    ++it; // now at 3rd element
    // Use *it to get the value
    cout << "Third element: " << *it << endl;
}