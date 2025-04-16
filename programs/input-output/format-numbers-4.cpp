#include <iostream>
#include <string>
#include <format>
using namespace std;

int main() {
    cout << "--------------" << endl;
    cout << format("{}", 97) << endl;
    cout << format("{:c}", 97) << endl;
    cout << format("{:b}", 97) << endl;
    cout << format("{:x}", 97) << endl;
    cout << "--------------" << endl;
}