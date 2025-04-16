#include <iostream>
using namespace std;

struct Time {
    int hour, minute;
};

// Return true if time1 is after time2, false otherwise
bool after(const Time& time1, const Time& time2) {
    if (time1.hour > time2.hour) { return true; }
    if (time1.hour < time2.hour) { return false; }
    if (time1.minute > time2.minute) { return true; }
    return false;
}

int main() {
    Time time = { 11, 59 };
    Time time2 = { 1, 50 };
    cout << after(time, time2);
}