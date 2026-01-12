#include <iostream>
#include <string>
#include <format>
using namespace std;

class Square {
public:
    static const int NUM_SIDES;  //class-level constant

    Square(double size) {
        m_sideLength = size;
    }
    void print() const {
        string s = format("Square with {} sides of length: {}",
                          NUM_SIDES,
                          m_sideLength);
        cout << s;
    }
private:
    double m_sideLength; // side length of the square
};

const int Square::NUM_SIDES = 4; // Initialize the static constant

int main()
{
    cout << "A square has " << Square::NUM_SIDES << " sides." << endl;
    Square s1(5.0);
    s1.print(); // Print the square's details
}