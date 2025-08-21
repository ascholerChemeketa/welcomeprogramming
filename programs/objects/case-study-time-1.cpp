#include <string>
using namespace std;

class Time {
public:
    Time(int hours, int minutes);
    int getHour();
    int getMinute();

private:
    int m_hours = 0;
    int m_minutes = 0;
};

// Fully specified time
Time::Time(int hours, int minutes) {
    // TODO: Fixme!
}

int Time::getHour() {
    return m_hours;
}

int Time::getMinute() {
    return m_minutes;
}
