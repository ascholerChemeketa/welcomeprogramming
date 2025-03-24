#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string toUpper(string s) {
    string result = "";
    for (char c : s) {
        result += toupper(c);
    }
    return result;
}

int main() {
    string message = "Stop shouting at me!";
    string yell = toUpper(message);
    cout << message << endl;
    cout << message << endl;
    cout << yell << endl;
}