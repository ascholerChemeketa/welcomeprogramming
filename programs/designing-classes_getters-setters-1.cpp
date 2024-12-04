#include <iostream>

struct Time {
    int hour;
    int minute;
    double second;
};

int main() {
    Time time = {11, 59, 59.9};
    cout << time.hour << endl;
    return 0;
}
