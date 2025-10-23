#include <iostream>
using namespace std;

int main() {
    int number = 5;
    while (number <= 25) {
        cout << number << endl;
        number = number + 5;  // or number += 5;
    }
}