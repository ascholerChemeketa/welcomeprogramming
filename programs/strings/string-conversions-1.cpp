#include <iostream>
#include <string>
using namespace std;

int main() {
    string dimensions = "12x8";

    // break up the string into two parts
    size_t xIndex = dimensions.find('x');
    string widthStr = dimensions.substr(0, xIndex);
    string heightStr = dimensions.substr(xIndex + 1);

    // turn the two parts into numbers
    double width = stod(widthStr);
    double height = stod(heightStr);

    double area = width * height;
    string message = "The area is ";
    message += to_string(area);
    message += " square units.";
    cout << message << endl;
}