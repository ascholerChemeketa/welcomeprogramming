/* This code checks if a number is positive and not zero and prints the result
 * to the console. */
#include <iostream>
using namespace std;

int main() {
    int x;
    // Get input from the user
    cout << "Enter an integer: ";
    cin >> x;

    // Check if x is positive and not zero
    if (x > 0) {
        cout << "x is positive" << endl;
        cout << "x is not zero" << endl;
    }
    return 0;
}