double calculateTax(double income, bool isMarried) {
    double tax = income;  // wrong, but it will compile...

    if (isMarried) {
        cout << "***MARRIED***" << endl;
    } else {
        cout << "***SINGLE***" << endl;
        if (income ???) {
            tax = income * 0.10;
        }
    }

    return tax;
}