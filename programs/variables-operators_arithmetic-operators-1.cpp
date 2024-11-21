#include <iostream>
int main() {
  int hour = 11;
  int minute = 59;
  cout << "Number of minutes since midnight: " << hour * 60 + minute
            << endl;
  return 0;
}