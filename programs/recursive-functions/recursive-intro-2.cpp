#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        cout << "Blastoff!" << endl;
    } else {
        countdown(n - 1); //recursive call
        cout << n << endl;
    }
}

int main() {
    countdown(3);
}