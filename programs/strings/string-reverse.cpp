#include <iostream>
#include <string>
using namespace std;

int main() {
    string myString = "Hello";
    string reversed = "";
    for (char letter : myString) {
        cout << "Current character: " << letter << endl;
        reversed = letter + reversed;
        cout << "Reversed: " << reversed << endl;
    }
}

