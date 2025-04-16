#include <string>
using namespace std;

class Time {
public:
    // Fully specified time
    Time(int hours, int minutes) {
        m_hours = hours;
        m_minutes = minutes;
    }

    int getHours() {
        return m_hours;
    }

    int getMinutes() {
        return m_minutes;
    }

private:
    int m_hours = 0;
    int m_minutes = 0;
};
