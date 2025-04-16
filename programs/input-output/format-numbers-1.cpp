#include <iostream>
#include <string>
#include <format>
using namespace std;

int main() {
    int a = 30;
    int b = -30;
    cout << format("_{}_{}_", a, b) << endl;
    cout << format("_{:+}_{:+}_", a, b) << endl;
    cout << format("_{: }_{: }_", a, b) << endl;
}