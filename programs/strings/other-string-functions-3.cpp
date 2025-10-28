#include <iostream>
#include <string>
using namespace std;

int main() {
    string message = "Hello world!";
    message.replace(6, 5, "you");
    cout << message << endl;
}