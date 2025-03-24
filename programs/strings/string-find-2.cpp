#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "She sells sea shells";
    char target = 'q';
    size_t foundIndex = myString.find(target);
    
    cout << "qIndex is " << foundIndex << endl;
    cout << "string::npos is " << string::npos << endl;

    if (foundIndex == string::npos) {
        cout << "No " << target << " in the string" << endl;
    } else {
        cout << "The " << target << " is at index " << foundIndex << endl;
    }
}