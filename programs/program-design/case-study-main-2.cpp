#include <iostream>

import DateFunctions;

using namespace std;

int main() {
    string startDate;
    cout << "Enter a start date in the format MM/DD/YYYY: ";
    cin >> startDate;
    //Echo input since activecode does not show it
    cout << endl << "You entered: " << startDate << endl;

    string endDate;
    cout << "Enter an end date in the format MM/DD/YYYY: ";
    cin >> endDate;
    //Echo input since activecode does not show it
    cout << endl << "You entered: " << endDate << endl;

    try {
        int startDayCount = dateToDays(startDate);
        int endDayCount = dateToDays(endDate);
        int daysBetween = endDayCount - startDayCount;
        cout << "The number of days between the two dates is: "
             << daysBetween << endl;
    } catch (const logic_error& e) {
        cout << "There was an error: " << e.what() << endl;
        cout << "Please try running the program again." << endl;
    }
}