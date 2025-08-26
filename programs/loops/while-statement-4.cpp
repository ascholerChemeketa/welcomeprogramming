#include <iostream>
using namespace std;

int main() {
    int x = 20;
    while (x < 10) {
        cout << "In the loop with x = " x << endl;
        x = x + 1;
    }
    cout << "All done!" << endl;
}