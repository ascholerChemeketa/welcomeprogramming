public Time() {
    new Time();         // StackOverflowError
    this.hour = 0;
    this.minute = 0;
    this.second = 0.0;
}