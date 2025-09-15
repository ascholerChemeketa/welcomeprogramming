#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Specify T as int. The 4.2 will be converted to 4
    cout << myMax<int>(3, 4.2) << endl;

    // Specify T as double. The 3 will be converted to 3.0
    cout << myMax<double>(3, 4.2) << endl;
}