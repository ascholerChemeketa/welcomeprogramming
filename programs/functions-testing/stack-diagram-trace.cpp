#include <iostream>
using namespace std;

int bar(int number) {
    int x = 3 * number;
    return x;
}

int foo(int num) {
    int x = 2 * num;
    return x;
}

int main() {
    int x = 5;
    int y = foo(x);
    int z = bar(12);
}