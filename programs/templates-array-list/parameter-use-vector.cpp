#include <iostream>
#include <format>
#include <vector>
using namespace std;

template <typename T>
void resetVector(vector<T>& vec) {
    for (T& item : vec) {
        item = T{};
    }
}

class Time {
public:
    int hours;
    int minutes;

    Time() {
        hours = 12;
        minutes = 0;
    }

    Time(int h, int m) {
        hours = h;
        minutes = m;
    }
};

int main() {
    vector<int> intVec = {1, 2, 3, 4, 5};
    resetVector(intVec);

    for (const int& item : intVec) {
        cout << item << " ";
    }
    cout << endl;

    vector<Time> timeVec = {Time(3, 45), Time(2, 18)};
    resetVector(timeVec);

    for (const Time& item : timeVec) {
        cout << format("{}:{:02} ", item.hours, item.minutes);
    }
    cout << endl;
}