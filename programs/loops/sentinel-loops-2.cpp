#include <iostream>
using namespace std;

int main() {
    cout << "All powers of 2 less than 1000:" << endl;
    int number = 1;
    while (number != 1000) {   // Bug!!!!
        cout << number << endl;
        number = number * 2;
    }
}