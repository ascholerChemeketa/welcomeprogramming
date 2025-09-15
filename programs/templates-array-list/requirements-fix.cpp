#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

struct Time {
    int hours;
    int minutes;

    // Define the > operator for Time
    bool operator>(const Time& other) const {
        if (hours != other.hours) {
            return hours > other.hours;
        }
        return minutes > other.minutes;
    }
};

int main() {
    Time t1 = {1, 30};
    Time t2 = {2, 15};
    // Now Time supports >, so this works
    Time result2 = myMax(t1, t2);
    cout << result2.hours << ":" << result2.minutes << endl;
}