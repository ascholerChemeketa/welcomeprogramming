#include <iostream>

using namespace std;

int prod(int m, int n) {
    if (m == n) {
        return n;
    } else {
        return n * prod(m, n - 1);
    }
}

int main() {
    cout << prod(1, 4) << endl; // Output: 24
    return 0;
}