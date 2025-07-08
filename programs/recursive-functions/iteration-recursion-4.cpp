#include <iostream>
#include <string>

using namespace std;

string cleanUpSpaces(const string& input, bool inSpace = false, int curIndex = 0) {
    if (curIndex >= input.length()) {
        return "";
    }

    char curChar = input.at(curIndex);
    string restCleaned = cleanUpSpaces(input, false, curIndex + 1);

    result = curChar + restCleaned;

    return result;
}

int main() {
    string input = "This  is   a   string   with extra      spaces.";
    string cleaned = cleanUpSpaces(input);
    cout << "Cleaned: '" << cleaned << "'" << endl;
}