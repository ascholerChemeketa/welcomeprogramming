#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "user@college.edu";

    // Get the substring starting at index 5 with no max
    string substring = myString.substr(5);
    cout << substring << endl;

    // start from index 5, get 3 characters
    string substring2 = myString.substr(5, 3);
    cout << substring2 << endl;

    // start from index 0, get 4 characters
    string substring3 = myString.substr(0, 4);
    cout << substring3 << endl;

    // start from index 0, get 1 characters
    string substring4 = myString.substr(0, 1);
    cout << substring4 << endl;

    cout << "myString is still " << myString << endl;
}