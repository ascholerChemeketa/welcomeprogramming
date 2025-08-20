#include <iostream>

import DateFunctions;

using namespace std;

string getInput(const string& prompt) {
    string input;
    cout << prompt;
    cin >> input;
    // Echo input since activecode does not show it
    cout << endl << "You entered: " << input << endl;
    return input;
}

int main() {
    string startDate = getInput("Enter a start date in the format MM/DD/YYYY: ");
    string endDate = getInput("Enter an end date in the format MM/DD/YYYY: ");

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