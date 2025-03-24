#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "Hello World";
    cout << "This looks like a bad idea..." << endl;
    cout << myString.at(100) << endl;
    cout << "Well, that didn't work." << endl;
}