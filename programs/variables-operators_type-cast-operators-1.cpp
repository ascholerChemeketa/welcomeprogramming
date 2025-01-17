#include <iostream>

using namespace std;

int main() {
    double pi = 3.14159;
    int x = static_cast<int>(pi);
    cout << "pi is still " << pi << endl;  // pi is still 3.14159
    cout << "x is " << x << endl;          // x is 3
}