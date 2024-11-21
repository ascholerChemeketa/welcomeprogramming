Time add(const Time& t2) const {
  Time sum;
  sum.hour = this->hour + t2.hour;
  sum.minute = this->minute + t2.minute;
  sum.second = this->second + t2.second;

  if (sum.second >= 60.0) {
    sum.second -= 60.0;
    sum.minute++;
  }
  if (sum.minute >= 60) {
    sum.minute -= 60;
    sum.hour++;
  }
  sum.hour %= 24; // This is more concise than the if statement
  return sum;
}