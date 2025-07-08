#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        cout << "Blastoff!" << endl;
    } else {
        cout << "Starting " << n << endl;
        countdown(n - 1); //recursive call
        cout << "Finishing " << n << endl;
    }
}

int main() {
    countdown(3);
}