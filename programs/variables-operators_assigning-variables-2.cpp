#include <iostream>
#include <string>

using namespace std;

int main() {
  string message = "123"; // Legal
  // message = 123; //Not legal - needs explicit conversion
  int num = 123;
  message = to_string(num); // Legal with conversion
  return 0;
}