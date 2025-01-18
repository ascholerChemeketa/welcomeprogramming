#include <iostream>

using namespace std;

int main() {
    // Prompt the user
    cout << "Enter your age in human years: ";

    // Get their input
    int humanYears;
    cin >> humanYears;

    // Calculate the age in dog years
    int dogYears = humanYears / 7;
    cout << "Your age in dog years is: " << dogYears << endl;
}