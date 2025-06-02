#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Silly {
protected:
  int x;

private:
  string s;

public:
  Silly(string sValue) {
    s = sValue;
  }

  string toString() const {
    return to_string(x) + " " + s;
  }
};