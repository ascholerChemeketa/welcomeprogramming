#include <iostream>
using namespace std;

struct Time {
    int hour, minute;
};

Time incrementPure(const Time& t) {
    Time incremented = t;
    incremented.minute += 1;
    if (incremented.minute == 60) {
        incremented.minute = 0;
        incremented.hour += 1;
        if (incremented.hour == 24) {
            incremented.hour = 0;
        }
    }
    return incremented;
}

int main() {
    Time time = { 11, 59 };
    Time time2 = incrementPure(time);
    cout << "Original time: " 
         << time.hour << ":" 
         << time.minute << endl;
    cout << "Incremented time: " 
         << time2.hour << ":" 
         << time2.minute << endl;
}