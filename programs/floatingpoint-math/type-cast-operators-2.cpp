#include <iostream>

using namespace std;

int main() {
    int one = 1;
    int three = 3;
    cout << (one / three) << endl;   // int division

    // force floating point division
    cout << (static_cast<double>(one) / three) << endl;
}