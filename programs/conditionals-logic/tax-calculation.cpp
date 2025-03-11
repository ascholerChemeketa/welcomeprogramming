#include <iostream>
using namespace std;

double calculateTax(double income, bool isMarried) {
    double tax = 0.0;
    if (isMarried) {
        if (income <= 20000) tax = income * 0.10;
        else if (income <= 50000) tax = 2000 + (income - 20000) * 0.15;
        else if (income <= 100000) tax = 6500 + (income - 50000) * 0.20;
        else tax = 16500 + (income - 100000) * 0.25;
    } else {
        if (income <= 10000) tax = income * 0.10;
        else if (income <= 30000) tax = 1000 + (income - 10000) * 0.15;
        else if (income <= 70000) tax = 4000 + (income - 30000) * 0.20;
        else tax = 12000 + (income - 70000) * 0.25;
    }
    return tax;
}

int main() {
    double income;
    char status;
    cout << "Enter your income: ";
    cin >> income;
    cout << "Enter your filing status (s for single, m for married): ";
    cin >> status;
    bool isMarried = (status == 'm');
    double tax = calculateTax(income, isMarried);
    cout << "Your tax is: $" << tax << endl;
    return 0;
}
