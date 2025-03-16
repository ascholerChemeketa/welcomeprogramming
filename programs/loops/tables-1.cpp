#include <iostream>
using namespace std;

int main() {
    const double START_VALUE = 10000.0;
    const double GROWTH_RATE = 0.20;
    const double TARGET = 100000.0;

    cout << "Year\tInvestment Amount" << endl;
    cout << "------------------------" << endl;
    int years = 1;
    double balance = START_VALUE;
    while (balance < TARGET) {
        cout << years << "\t$" << balance << endl;
        // Updates
        years++;
        double interest = balance * GROWTH_RATE;
        balance += interest;
    }
    cout << years << "\t$" << balance << endl;
}