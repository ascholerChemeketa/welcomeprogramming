#include <iostream>
#include <string>

using namespace std;

int main() {
    int age;
    string name;
    cout << "What is your age? ";
    cin >> age;
    cin.ignore(); // consume newline
    cout << "What is your name? ";
    getline(cin, name);
    cout << "Hello " << name << ", age " << age << endl;
    return 0;
}