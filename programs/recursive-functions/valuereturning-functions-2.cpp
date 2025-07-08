#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        cout << "Returning 1 for factorial(0)" << endl;
        return 1;
    } else {
        int nMinusOneAnswer = factorial(n - 1);
        int result = n * nMinusOneAnswer;
        cout << "Returning " << result 
             << " for factorial(" << n << ")" << endl;
        return result;
    }
}

int main() {
    int fact = factorial(3);
    cout << "Factorial of 3 is: " << fact << endl;
}