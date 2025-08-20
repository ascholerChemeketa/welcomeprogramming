module;

#include <string>
#include <stdexcept>

export module DateFunctions;

using namespace std;

export int getDay(const string& date) {
    // TODO: Fix this stub version!!!
    // Assume day is index 3 to 5
    string dayPart = date.substr(3, 5);
    int dayNum = stoi(dayPart);
    return dayNum;
}

export int getYear(const string& date) {
    // TODO: Fix this stub version!!!
    // Assume year starts at index 6
    string yearString = date.substr(6);
    int yearNum = stoi(yearString);
    return yearNum;
}

export int getMonth(const string& date) {
    size_t slash = date.find('/');
    if (slash == string::npos) {
        throw logic_error("Date must contain '/'");
    }

    string monthPart = date.substr(0, slash);
    // stoi will throw exceptions for invalid input
    int monthNum = stoi(monthPart);

    if (monthNum < 1 || monthNum > 12) {
        throw logic_error("Month out of range");
    }

    // If we reach here, the month is valid
    return monthNum;
}