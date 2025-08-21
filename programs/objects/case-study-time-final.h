#ifndef CASE_STUDY_TIME_FINAL_H
#define CASE_STUDY_TIME_FINAL_H

#include <string>

/**
 * @brief A class representing a time of day.
 */
class Time {
public:
    /**
     * @brief Constructs a Time object with the specified hours and minutes.
     * @param hours The hour part of the time (0-23).
     * @param minutes The minute part of the time (0-59).
     */
    Time(int hours, int minutes);

    /**
     * @brief Gets the hour part of the time.
     * @return The hour part of the time (0-23).
     */
    int getHour();

    /**
     * @brief Gets the minute part of the time.
     * @return The minute part of the time (0-59).
     */
    int getMinute();

    /**
     * @brief Converts the time to a string in 24-hour format.
     * @return A string representation of the time in "HH:MM" format.
     */
    std::string toString24Hour();

    /**
     * @brief Converts the time to a string in 12-hour format.
     * @return A string representation of the time in "HH:MM AM/PM" format.
     */
    std::string toString12Hour();

    /**
     * @brief Sets the hour part of the time.
     * @param hour The hour to set (0-23).
     */

    void setHour(int hour);
    /**
     * @brief Sets the minute part of the time.
     * @param minute The minute to set (0-59).
     */

    void setMinute(int minute);

    /**
     * @brief Sets both the hour and minute parts of the time.
     * @param hour The hour to set (0-23).
     * @param minute The minute to set (0-59).
     */
    void setTime(int hour, int minute);

    /**
     * @brief Adds minutes to the current time.
     * If the addition causes the minutes to exceed 59, it wraps around and
     * updates the hour accordingly.
     * @param minutes The number of minutes to add.
     */
    void addMinutes(int minutes);

private:
    /**
     * @brief Validates the hour and minute values.
     * Throws an exception if the values are invalid.
     * @param hours The hour to validate (0-23).
     * @param minutes The minute to validate (0-59).
     */
    void validate(int hours, int minutes);

    int m_hours = 0;
    int m_minutes = 0;
};

#endif // CASE_STUDY_TIME_FINAL_H