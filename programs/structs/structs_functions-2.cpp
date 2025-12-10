#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

Point mirrorOverY(const Point& p1) {
    // Copy p1 to mirrored
    Point mirrored = p1;
    // Mirror over the y-axis
    mirrored.x = -mirrored.x;
    return mirrored;
}

int main() {
    Point point = { 3.0, 4.0 };
    Point mirrorImage = mirrorOverY(point);
    cout << "The mirror image is ("
         << mirrorImage.x << ", " 
         << mirrorImage.y << ")" 
         << endl;
}