module;

#include <string>
#include <stdexcept>

export module DateFunctions;

using namespace std;

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