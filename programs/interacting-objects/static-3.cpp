#include <iostream>
#include <string>
using namespace std;

class Square {
public:
    // A static factory function to create a square object
    static Square create(double size) {
        // Make some decisions about how to construct the square
        Square s(size); // Call the private constructor
        // do some fancy other work
        return s; // Return the square object
    }

private:
    // A private constructor that outside code cannot access
    Square(double size) {
        m_sideLength = size;
    }
    double m_sideLength; // side length of the square
};

int main()
{
    // Can't use constructor directly
    // Square s1(5.0); // Error: constructor is private

    // Must use the static method to create a square
    Square s1 = Square::create(5.0); // Use the static method to create a square
}