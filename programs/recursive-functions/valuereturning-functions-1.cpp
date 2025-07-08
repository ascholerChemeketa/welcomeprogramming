#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1; // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int fact = factorial(5);
    cout << "Factorial of 5 is: " << fact << endl;
}