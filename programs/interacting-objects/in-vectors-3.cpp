#include <iostream>
#include <vector>
using namespace std;

import SimplePoint; // Import the module with SimplePoint1 and SimplePoint2

int main()
{
    // This works because SimplePoint2 has a default constructor
    vector<SimplePoint2> points1(5);

    // Make a vector of SimplePoint1 objects with explicit construction
    vector<SimplePoint1> points2(5, SimplePoint1(5.0, 5.0));

    // Make a vector of SimplePoint1 objects from  list
    vector<SimplePoint1> points3 = {
      SimplePoint1(0.0, 0.0), 
      SimplePoint1(1.0, 2.0),
      SimplePoint1(2.0, 3.0)
    };

    // Now use some points
    cout << points1.at(0).getX() << endl; // Access the first element from points1's x
    cout << points2.at(2).getX() << endl; // Access the third element from points2's x

    // Loop through points3 and print their x values
    for (const SimplePoint1& point : points3) {
        cout << point.getX() << " ";
    }
}