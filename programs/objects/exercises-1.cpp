/* This function takes an integer x and a Point p as input. It adds 7 to x, then
 * returns the sum of the modified x, p.x, and p.y. */
#include <iostream>

// Assuming Point structure exists.  If not, define it.
struct Point {
    int x, y;
};

int riddle(int x, Point p) {
    x = x + 7;
    return x + p.x + p.y;
}

int main() {
    Point p = {1, 2};
    cout << riddle(5, p) << endl; // Example usage
    return 0;
}