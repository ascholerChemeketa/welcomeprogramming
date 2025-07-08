#include <iostream>
using namespace std;

int addDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int lastDigit = n % 10; // Get the last digit
        sum += lastDigit;
        n /= 10; // Remove the last digit
    }
    return sum;
}

int main() {
    int number = 532;
    int digitSum = addDigits(number);
    cout << "The sum of digits in " << number << " is: " << digitSum << endl;
}