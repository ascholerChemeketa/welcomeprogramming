double calculateTax(double income, bool isMarried) {
    double tax = income;  // wrong, but it will compile...

    if (isMarried) {
        cout << "***MARRIED***" << endl;
    } else {
        cout << "***SINGLE***" << endl;
        if (income <= 1000) {
            tax = income * 0.10;
        } else if (income <= 30000) {
            tax = 1000 + (income - 10000) * 0.15;
        } else if (income <= 70000) {
            tax = ???;
        } else {
          tax = 12000 + (income - 70000) * 0.25;
        }
      }
    }

    return tax;
}