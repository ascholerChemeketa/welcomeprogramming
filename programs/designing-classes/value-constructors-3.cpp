struct Time {
    int hour;
    int minute;
    double second;

    Time(): hour(0), minute(0), second(0.0) {
    }

    Time(int hour, int minute, double second):
        hour(hour), minute(minute), second(second) {
    }
};