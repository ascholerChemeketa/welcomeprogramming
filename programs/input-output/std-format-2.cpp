#include <iostream>
#include <string>
#include <format>
using namespace std;

int main() {
    string name = "Alice";
    int age = 30;
    double height = 5.7;
    string message = format("Hello, {}! You are {} years old and {} feet tall.", name, age, height);
    cout << message << endl;
}