module;

#include <stdexcept>
#include <string>

export module Time;

using namespace std;

/**
 * @brief A class representing a time of day.
 */
export class Time {
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
    string toString24Hour();

    /**
     * @brief Converts the time to a string in 12-hour format.
     * @return A string representation of the time in "HH:MM AM/PM" format.
     */
    string toString12Hour();

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

Time::Time(int hours, int minutes) {
    // check the values, throw an exception if they are invalid
    validate(hours, minutes);
    // otherwise safe to use them
    m_hours = hours;
    m_minutes = minutes;
}

void Time::validate(int hours, int minutes) {
    if (hours < 0 || hours > 23) {
        throw logic_error("Invalid hours value in time");
    }
    if (minutes < 0 || minutes > 59) {
        throw logic_error("Invalid minutes value in time");
    }
}

int Time::getHour() {
    return m_hours;
}

int Time::getMinute() {
    return m_minutes;
}

void Time::setHour(int hour) {
    validate(hour, 1); // valid dummy value for minutes
    m_hours = hour;
}

void Time::setMinute(int minute) {
    validate(1, minute); // valid dummy value for hours
    m_minutes = minute;
}

void Time::setTime(int hour, int minute) {
    validate(hour, minute);
    m_hours = hour;
    m_minutes = minute;
}

string Time::toString24Hour() {
    // minutes should always be 2 digits, use 0 to pad
    string tString = format("{}:{:0>2}", m_hours, m_minutes);
    return tString;
}

string Time::toString12Hour() {
    string ampm = (m_hours & lt; 12) ? "AM" : "PM";

    // decide what hour to display
    int displayHour = m_hours % 12;
    if (displayHour == 0) {
        displayHour = 12;
    }

    string tString = format("{}:{:0>2} {}", displayHour, m_minutes, ampm);
    return tString;
}

void Time::addMinutes(int minutes) {
    m_minutes += minutes;

    // if minutes is now greater than 59,
    // wrap and update the number of hours
    if (m_minutes > 59) {
        m_hours += m_minutes / 60;
        m_minutes = m_minutes % 60;
    }

    // if hours is now greater than 23
    // fix it
    if (m_hours > 23) {
        m_hours = m_hours % 24;
    }
}