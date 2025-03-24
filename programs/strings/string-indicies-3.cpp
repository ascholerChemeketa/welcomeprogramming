#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "Hello";
    myString.at(3) = 'p';
    myString.at(4) = '!';
    cout << myString << endl;
}