#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double cm;
    int feet, inches, remainder;
    const double CM_PER_INCH = 2.54;
    const int IN_PER_FOOT = 12;

    // prompt the user and get the value
    cout << "Exactly how many cm? ";
    cin >> cm;

    // Input validation. If input fails, clear error flags and discard the bad
    // input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please enter a valid number.\n";
        return 1; // Indicate an error
    }

    // convert and output the result
    inches = (int)(cm / CM_PER_INCH);
    feet = inches / IN_PER_FOOT;
    remainder = inches % IN_PER_FOOT;
    cout << fixed << setprecision(2) << cm << " cm = " << feet << " ft, "
         << remainder << " in" << endl;
    return 0;
}