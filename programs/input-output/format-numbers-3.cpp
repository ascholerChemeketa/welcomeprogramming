#include <iostream>
#include <string>
#include <format>
using namespace std;

int main() {
    double a = 123.456789;
    cout << "Fixed decimal:" << endl;
    cout << format("{:.1f}", a) << endl;
    cout << format("{:.2f}", a) << endl;
    cout << format("{:.3f}", a) << endl;
    cout << "Scientific (floating decimal):" << endl;
    cout << format("{:.1e}", a) << endl;
    cout << format("{:.2e}", a) << endl;
    cout << format("{:.3e}", a) << endl;
}