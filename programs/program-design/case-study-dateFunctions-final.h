#ifndef DATE_FUNCTIONS_H
#define DATE_FUNCTIONS_H

#include <string>

// We do NOT want to use "using namespace std;" in header files
// because it can lead to name conflicts in larger projects.
// Instead we will use std::string and other std:: types explicitly.

/** @brief Extracts the day from a date string in the format "MM/DD/YYYY".
 * 
 * @param date The date string to extract the day from.
 * @return The day as an integer.
 * @warning Sanity checks that the day is not > 31. Does not check for valid days in months (e.g., February 30).
 */
int getDay(const std::string& date);

/** @brief Extracts the year from a date string in the format "MM/DD/YYYY".
 * 
 * @param date The date string to extract the year from.
 * @return The year as an integer.
 */
int getYear(const std::string& date);

/** @brief Extracts the month from a date string in the format "MM/DD/YYYY".
 * 
 * @param date The date string to extract the month from.
 * @return The month as an integer.
 */
int getMonth(const std::string& date);

/** @brief Calculates the number of days before a given month in a non-leap year.
 * 
 * @param month The month to calculate the days before.
 * @return The number of days before the given month.
 */
int daysBeforeMonth(int month);

/** @brief Converts a date string in the format "MM/DD/YYYY" to the total number of days since the start of 0000. 1/1/0000 is considered day 1.
 * 
 * @param date The date string to convert.
 * @return The total number of days since the start of 0000.
 * 
 * @warning Assumes leap years do not exist
 */
int dateToDays(const std::string& date);

#endif // DATE_FUNCTIONS_H