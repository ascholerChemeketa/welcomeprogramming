Time add(const Time& t2) const {
  Time sum;
  sum.hour = this->hour + t2.hour;
  sum.minute = this->minute + t2.minute;
  sum.second = this->second + t2.second;
  return sum;
}