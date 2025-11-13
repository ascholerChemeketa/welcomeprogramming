#include <iostream>
#include <string>
#include <format>
using namespace std;

int main() {
    int a = 12345;
    int b = 789;
    cout << "2 chars space:" << endl;
    cout << format("_{:2}_", a) << endl;
    cout << format("_{:2}_", b) << endl;
    cout << "5 chars space:" << endl;
    cout << format("_{:5}_", a) << endl;
    cout << format("_{:5}_", b) << endl;
    cout << "10 chars space:" << endl;
    cout << format("_{:10}_", a) << endl;
    cout << format("_{:10}_", b) << endl;
}