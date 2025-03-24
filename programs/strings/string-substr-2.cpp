#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter your email address: " << endl;
    string email;
    cin >> email;

    size_t atIndex = email.find('@');
    cout << "atIndex is " << atIndex << endl;

    if (atIndex == string::npos) {
        cout << "Invalid email address" << endl;
    } else {
        // location we found == number of character before the @
        string username = email.substr(0, atIndex);
        cout << "Username: " << username << endl;
        // rest of the string starts 1 after the @
        string domain = email.substr(atIndex + 1);
        cout << "Domain: " << domain << endl;
    }
}