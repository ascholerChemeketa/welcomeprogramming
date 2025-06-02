#include <iostream>
#include <string>

import GeometricObject;
import Rectangle;
import Circle;

using namespace std;

void checkObject(GeometricObject& g) {
    string data = g.toString();
    cout << data << endl;
    cout << "Area: " << g.getArea() << endl;
}

int main() {
    Rectangle rect(3.0, 4.0, "red");
    Circle circ(5.0, "blue");

    checkObject(rect);
    checkObject(circ);
}