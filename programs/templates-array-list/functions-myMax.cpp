#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(3, 7) << endl;        // T is int
    cout << myMax(3.5, 2.1) << endl;    // T is double
    cout << myMax('a', 'z') << endl;    // T is char
}