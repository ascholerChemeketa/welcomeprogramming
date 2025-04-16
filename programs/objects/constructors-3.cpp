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
        m_seconds = 0;
    }

    // Assume minutes and seconds are 0
    Time(int hours) {
        m_hours = hours;
        m_minutes = 0;
        m_seconds = 0;
    }

    // Default constructor
    Time() {
        m_hours = 0;
        m_minutes = 0;
        m_seconds = 0;
    }
private:
    int m_hours, m_minutes, m_seconds;
};