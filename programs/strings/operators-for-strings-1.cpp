#include <iostream>
#include <string>
using namespace std;

int main() {
    string string1 = "apple";
    string string2 = "apple";
    string string3 = "Apple";
    string string4 = "Banana";

    cout << string1 << " == " << string2 << "? "
         << (string1 == string2) << endl;

    cout << string1 << " == " << string4 << "? "
         << (string1 == string4) << endl;

    cout << string1 << " == " << string3 << "? " 
        << (string1 == string3) << endl;


    cout << string3 << " < " << string4 << "? " 
    << (string3 < string4) << endl;

    cout << string1 << " < " << string4 << "? " 
        << (string1 < string4) << endl;
}