#include <iostream>

struct Point {
    int x, y;
};

int main() {
    Point blank = {3, 4}; // Example Point
    cout << blank.x << ", " << blank.y << endl;
    int sum = blank.x * blank.x + blank.y * blank.y;
    cout << sum << endl; // prints 25
    return 0;
}