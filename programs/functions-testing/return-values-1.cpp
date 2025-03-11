void printAsMoney(double dollars) {
    // round to the nearest cent
    double cents = dollars * 100;
    cents = round(cents);
    dollars = cents / 100.0;
    // then print
    cout << "$" << dollars << endl;
}