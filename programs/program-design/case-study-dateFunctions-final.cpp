#include <string>
#include <stdexcept>

#include "dateFunctions.h"

using namespace std;

// NOTE: This function is not listed in the .h file as it is not designed to
// be used outside of this file. Thus the function comment is here.
/** @brief Checks if a string contains only digits.
 * 
 * @param str The string to check.
 * @return true if string contains only digits, false otherwise.
 */
bool isAllDigits(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int getDay(const string& date) {
    size_t slash = date.find('/');
    if (slash == string::npos) {
        throw logic_error("Date must contain '/'");
    }

    string afterSlash = date.substr(slash + 1);
    size_t nextSlash = afterSlash.find('/');
    if (nextSlash == string::npos) {
        throw logic_error("Date must contain two '/' characters");
    }

    string dayPart = afterSlash.substr(0, nextSlash);
    if(!isAllDigits(dayPart)) {
        throw logic_error("Day must be a number");
    }

    int dayNum = stoi(dayPart);

    if (dayNum < 1 || dayNum > 31) {
        throw logic_error("Day out of range");
    }

    return dayNum;
}

int getYear(const string& date) {
    size_t slash = date.find('/');
    if (slash == string::npos) {
        throw logic_error("Date must contain '/'");
    }

    string afterSlash = date.substr(slash + 1);
    size_t nextSlash = afterSlash.find('/');
    if (nextSlash == string::npos) {
        throw logic_error("Date must contain two '/' characters");
    }

    string yearPart = afterSlash.substr(nextSlash + 1);
    if(!isAllDigits(yearPart)) {
        throw logic_error("Year must be a number");
    }

    int yearNum = stoi(yearPart);
    return yearNum;
}


int getMonth(const string& date) {
    size_t slash = date.find('/');
    if (slash == string::npos) {
        throw logic_error("Date must contain '/'");
    }

    string monthPart = date.substr(0, slash);
    if(!isAllDigits(monthPart)) {
        throw logic_error("Month must be a number");
    }

    int monthNum = stoi(monthPart);

    if (monthNum < 1 || monthNum > 12) {
        throw logic_error("Month out of range");
    }

    // If we reach here, the month is valid
    return monthNum;
}

int daysBeforeMonth(int month) {
    //implement with switch statement
    switch (month) {
        case 1: return 0;
        case 2: return 31;
        case 3: return 59;
        case 4: return 90;
        case 5: return 120;
        case 6: return 151;
        case 7: return 181;
        case 8: return 212;
        case 9: return 243;
        case 10: return 273;
        case 11: return 304;
        case 12: return 334;
        default: throw logic_error("Invalid month");
    }
}

int dateToDays(const string& date) {
    int month = getMonth(date);
    int day = getDay(date);
    int year = getYear(date);

    int totalDays = daysBeforeMonth(month) + day + year * 365;
    return totalDays;
}