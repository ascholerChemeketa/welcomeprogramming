#include <iostream>

import DateFunctions;

using namespace std;

int main() {
    string startDate;
    cout << "Enter a start date in the format MM/DD/YYYY: ";
    cin >> startDate;
    //Echo input since activecode does not show it
    cout << endl << "You entered: " << startDate << endl;

    try {
        int month = getMonth(startDate);
        cout << "The month is: " << month << endl;
    } catch (const logic_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}