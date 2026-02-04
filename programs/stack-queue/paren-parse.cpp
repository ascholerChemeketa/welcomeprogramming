#include <iostream>
#include <stack>

using namespace std;

bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

void checkParens(const string& expression) {
    stack<char> parens;

    cout << "Parsing expression: " << expression << endl;

    bool errorFound = false;
    for(char curChar : expression) {
        switch(curChar) {
            case '(' :
            case '[' :
            case '{' : 
                cout << "Pushing " << curChar << endl;
                parens.push(curChar); break;
            case ')' :
            case ']' :
            case '}' :
                if(parens.empty() || !isMatch(parens.top(), curChar)) {
                    cout << " error matching " << (parens.empty() ? ' ' : parens.top()) << " with " << curChar << endl;
                    errorFound = true;
                }
                else {
                    cout << " matched " << parens.top() << " with " << curChar << endl;
                    parens.pop();  // found a matching pair
                }
                break;
            default:    //do nothing for other chars
                break;
        }
        if(errorFound)
            break; // no need to keep going
    }

    if(errorFound)
        cout << "Parens do not match" << endl;
    else if(!parens.empty())
        cout << "Unmatched opening paren(s) remain" << endl;
    else
        cout << "Parens match" << endl;
    cout << "-------------------------" << endl;
}

int main() {
    checkParens("(a + b)");
    checkParens("(a + b]");
    checkParens("([a + b] - c)");
    checkParens("(a + b) * {c - [d / (e + f)]}");
    checkParens("((a + b) - c");
}