#include <iostream>
#include <string>
#include <format>
using namespace std;

int main() {
    string name = "Alice";
    int age = 30;
    string message = format("Hello, {}! You are {} years old.", name, age);
    cout << message << endl;
}