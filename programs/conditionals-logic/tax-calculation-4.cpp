double calculateTax(double income, bool isMarried) {
    double tax = 0;

    if (isMarried) {
        if (income <= 20000) {
            tax = income * 0.10;
        }
        else if (income <= 50000) {
            tax = 2000 + (income - 20000) * 0.15;
        }
        else if (???) {
            tax = 6500 + (income - 50000) * 0.20;
        }
        else {
            tax = ???;
        }
    } else {
        //PASTE YOUR CODE FROM THE PREVIOUS ACTIVITY HERE
    }

    return tax;
}