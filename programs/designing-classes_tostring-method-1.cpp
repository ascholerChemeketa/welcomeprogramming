#include <iomanip>
#include <iostream>

struct Time {
  int hour;
  int minute;
  double second;
};

ostream& operator<<(ostream& os, const Time& time) {
  os << setfill('0') << setw(2) << time.hour << ":" << setfill('0') << setw(2)
     << time.minute << ":" << fixed << setprecision(1) << time.second;
  return os;
}

int main() {
  Time time = {11, 59, 59.9};
  cout << time << endl;
  return 0;
}
