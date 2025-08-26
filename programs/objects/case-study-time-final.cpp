#include <stdexcept>
#include "Time.h"

using namespace std;

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