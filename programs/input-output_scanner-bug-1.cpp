#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int age;
    cout << "What is your name? ";
    getline(cin, name);
    cout << "What is your age? ";
    cin >> age;
    cout << "Hello " << name << ", age " << age << endl;
    return 0;
}