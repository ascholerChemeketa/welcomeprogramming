#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "Hello World";
    cout << myString.at(0) << endl;
    cout << myString.at(1) << endl;
    cout << myString.at(2) << endl;
    cout << "..." << endl;
    size_t length = myString.size();
    char last = myString.at(length - 1);
    cout << last;
}