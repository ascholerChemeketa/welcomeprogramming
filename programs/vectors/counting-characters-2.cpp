#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    // R"(string)" is a raw string literal and can span multiple lines
    string testString = R"(
        This is a test string.
        It contains some text.
    )";
    
    for(char c : testString) {
        char lower = static_cast<char>( tolower(c) );
        if ( isalpha(lower) ) {
            int index = lower - 'a';
            cout << lower << " " << index << endl;
        }
    }
}
