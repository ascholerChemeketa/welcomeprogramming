#include <iostream>
#include <string>
#include <format>
using namespace std;

int main() {
    int hours = 4;
    int minutes = 55;
    string name = "Alicia";
    double amount = 1234.5623;
    cout << format("{:>2}:{:0>2} | {:<16} | ${:>12.2f}", hours, minutes, name, amount) << endl;

    int hours2 = 12;
    int minutes2 = 1;
    string name2 = "Mario";
    double amount2 = 6.32;
    cout << format("{:>2}:{:0>2} | {:<16} | ${:>12.2f}", hours2, minutes2, name2, amount2) << endl;
}