#include <iostream>
using namespace std;

int main() {
    double hours = 45.5; // example input
    double rate = 18.5;  // Assume $18.50 per hour

    if (hours > 40) {
        // normal pay for 40 hours, then 1.5x pay for overtime
        // pay is created in this block and is not accessible outside of it
        double pay = 40 * rate + (hours - 40) * rate * 1.5;
    } else {
        // pay is created in this block and is not accessible outside of it
        double pay = hours * rate;
    }

    // pay is out of scope here!
    cout << "Pay: " << pay << endl;
}