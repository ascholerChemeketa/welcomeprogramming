string timeString(int hour, int minute) {
    string ampm;
    if (hour < 12) {
        ampm = "AM";
        if (hour == 0) {
            hour = 12;
        }
    } else {
        ampm = "PM";
        hour %= 12;
    }
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%02d:%02d %s", hour, minute,
             ampm.c_str());
    return string(buffer);
}