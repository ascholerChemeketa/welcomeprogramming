#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double x;
  cout << "Enter a number: ";
  cin >> x;
  double y = log(x);
  cout << "The log is " << y << endl;
  return 0;
}