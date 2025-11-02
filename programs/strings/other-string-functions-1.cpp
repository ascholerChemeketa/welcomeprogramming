#include <iostream>
#include <string>
using namespace std;

int main() {
    string message = "Hello there student!";
    message.erase(5, 6); // Erase 6 characters starting at index 5
    cout << message << endl;

    string message2 = "Hello there student!";
    message2.erase(2); // Erase from index 2 to the end
    cout << message2 << endl;
}