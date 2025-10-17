#include <iostream>
using namespace std;

int main() {
    double hours = 45.5; // example input
    double rate = 18.5;  // Assume $18.50 per hour

    double pay = 0; // pay is created here and is accessible throughout the function
    if (hours > 40) {
        // normal pay for 40 hours, then 1.5x pay for overtime
        pay = 40 * rate + (hours - 40) * rate * 1.5;
    } else {
        pay = hours * rate;
    }

    cout << "Pay: " << pay << endl;
}