#include <iostream>

import Point;

using namespace std;

int main() {
    Point p1(3.0, 4.0);
    Point* myPointer = &p1;

    cout << *myPointer.getX() << endl;  //problem...
}