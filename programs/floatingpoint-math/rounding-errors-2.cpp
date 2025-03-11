#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double balance = 123.45; // potential rounding error
    cout << fixed << setprecision(10) << balance << endl;
    return 0;
}