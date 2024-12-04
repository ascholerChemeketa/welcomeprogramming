#include <iostream>

void loop(int n) {
    int i = n;
    while (i > 1) {
        cout << i << endl;
        if (i % 2 == 0) {
            i = i / 2;
        } else {
            i = i + 1;
        }
    }
}

int main() {
    loop(10);
    return 0;
}