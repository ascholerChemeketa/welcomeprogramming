#include <iostream>

void countup(int n) {
    if (n == 0) {
        cout << "Blastoff!\n";
    } else {
        countup(n - 1);
        cout << n << "\n";
    }
}