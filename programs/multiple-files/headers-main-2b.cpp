#include <iostream>
using namespace std;

// Provide a second definition of the function doubleValue
// Instead of declaring that it exists elsewhere
int doubleValue(int num) {
    return num * 2;
}

int main() {
    int x = 5;
    cout << doubleValue(x);
}