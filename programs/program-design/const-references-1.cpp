#include <iostream>
using namespace std;

void add(const int& x) {
    x += 1; // increment x
}

int main() {
    int number = 5;
    add(number);
}