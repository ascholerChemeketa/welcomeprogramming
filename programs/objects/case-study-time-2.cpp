#include <string>
using namespace std;

class Time {
public:
    // Fully specified time
    Time(int hours, int minutes) {
        m_hours = hours;
        m_minutes = minutes;
    }


    // Assume minutes is 0
    Time(int hours) {
        m_hours = hours;
    }

    // Default constructor
    Time() {}

private:
    int m_hours = 0;
    int m_minutes = 0;
};
