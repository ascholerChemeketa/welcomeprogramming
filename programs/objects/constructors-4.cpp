class Time {
public:
    // Fully specified time
    Time(int hours, int minutes, int seconds) {
        m_hours = hours;
        m_minutes = minutes;
        m_seconds = seconds;
    }

    // Assume seconds is 0
    Time(int hours, int minutes) {
        m_hours = hours;
        m_minutes = minutes;
    }

    // Assume minutes and seconds are 0
    Time(int hours) {
        m_hours = hours;
    }

    // Default constructor
    Time() {
        // All members default to 0
    }
private:
    int m_hours = 0;
    int m_minutes = 0;
    int m_seconds = 0;
};