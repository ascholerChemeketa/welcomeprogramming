module;

#include <string>
#include <stdexcept>

export module DateFunctions;

using namespace std;

// NOTE: This function is not exported, so it is only available within this module.
// It is just designed to help with the implementation of the "main" exported functions.
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

/** @brief Extracts the day from a date string in the format "MM/DD/YYYY".
 * 
 * @param date The date string to extract the day from.
 * @return The day as an integer.
 * @warning Sanity checks that the day is not > 31. Does not check for valid days in months (e.g., February 30).
 */
export int getDay(const string& date) {
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

/** @brief Extracts the year from a date string in the format "MM/DD/YYYY".
 * 
 * @param date The date string to extract the year from.
 * @return The year as an integer.
 */
export int getYear(const string& date) {
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

/** @brief Extracts the month from a date string in the format "MM/DD/YYYY".
 * 
 * @param date The date string to extract the month from.
 * @return The month as an integer.
 */
export int getMonth(const string& date) {
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

/** @brief Calculates the number of days before a given month in a non-leap year.
 * 
 * @param month The month to calculate the days before.
 * @return The number of days before the given month.
 */
export int daysBeforeMonth(int month) {
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

/** @brief Converts a date string in the format "MM/DD/YYYY" to the total number of days since the start of 0000. 1/1/0000 is considered day 1.
 * 
 * @param date The date string to convert.
 * @return The total number of days since the start of 0000.
 * 
 * @warning Assumes leap years do not exist
 */
export int dateToDays(const string& date) {
    int month = getMonth(date);
    int day = getDay(date);
    int year = getYear(date);

    int totalDays = daysBeforeMonth(month) + day + year * 365;
    return totalDays;
}