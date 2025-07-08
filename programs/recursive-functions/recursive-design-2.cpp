#include <iostream>
using namespace std;

int addDigits(int n) {
  if (n < 10) {
      return n;
  } else {
      return addDigits(n / 10) + (n % 10);
  }
}

int main() {
    int number;
    cout << "Enter a number: " << cout;
    cin >> number;
    int digitSum = addDigits(number);
    cout << "The sum of digits in " << number << " is: " << digitSum << endl;
}

