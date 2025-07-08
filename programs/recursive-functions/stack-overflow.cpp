#include <iostream>

using namespace std;

void countdown(int n) {
    cout << n << endl; // Print the current value of n
    countdown(n - 1); //recursive call
}

int main() {
    countdown(3);
}