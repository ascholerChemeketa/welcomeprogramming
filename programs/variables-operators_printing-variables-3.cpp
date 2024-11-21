#include <iomanip>
#include <iostream>
int main() {
  int hour = 11;
  int minute = 59;
  cout << "The current time is " << setfill('0') << setw(2)
            << hour << ":" << setfill('0') << setw(2) << minute << "."
            << endl;
  return 0;
}