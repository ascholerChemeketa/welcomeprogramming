#include <iostream>
using namespace std;

int main() {
    int total = 0;
    int i = 1;
    while (i <= 5) {
        ++i;          // update i first
        total += i;
    }
    cout << total;
}