#include <iostream>

using namespace std;

int main() {
    int one = 1;
    int three = 3;
    cout << (one / three) << endl;
    cout << (static_cast<int>(one) / three) << endl;
}