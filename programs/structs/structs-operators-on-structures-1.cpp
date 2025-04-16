#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

int main() {
    Point p1 = {3.0, 4.0};
    // Copy p1 to p2
    Point p2 = p1;
    // change p2. p1 is unchanged
    p2.x = 5.0;
}
