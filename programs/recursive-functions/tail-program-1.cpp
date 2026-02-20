#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        int total = n * factorial(n - 1);
        return total;
    }
}

int main() {
    // This will be a problem...
    int fact = factorial(200000);
    cout << "Result: " << fact << endl;
}