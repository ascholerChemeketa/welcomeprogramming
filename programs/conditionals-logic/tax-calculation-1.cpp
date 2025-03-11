double calculateTax(double income, bool isMarried) {
    double tax = income;  // wrong, but it will compile...

    if (isMarried) {
        cout << "***MARRIED***" << endl;
    } else {
        cout << "***SINGLE***" << endl;
    }

    return tax;
}
