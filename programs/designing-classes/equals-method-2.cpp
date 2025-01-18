bool equals(const Time& that) const {
    constexpr double DELTA = 0.001;
    return this->hour == that.hour && this->minute == that.minute
           && abs(this->second - that.second) < DELTA;
}
