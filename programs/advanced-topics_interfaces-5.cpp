/*
 * This code snippet shows how to create instances of the RegularPolygon class
 * in Java and then cast them into Actor instances.
 */
#include <string>

// Assuming necessary headers for RegularPolygon, Actor, and Color are included.

// Assuming definitions for RegularPolygon, Actor, and Color exist.
class RegularPolygon {
  public:
    RegularPolygon(int numSides, double size, string color):
        numSides(numSides), size(size), color(color) {
    }

  private:
    int numSides;
    double size;
    string color;
};

class Actor {};

int main() {
    // The following code is a direct translation of the original Java code into
    // C++. Note that the translation assumes the existence of a class named
    // Color. In the absence of specific details about this class, it is assumed
    // that its constructor accepts a string as a parameter.
    RegularPolygon p2(5, 50, "YELLOW");
    Actor* a2 =
        new RegularPolygon(5, 50,
                           "YELLOW"); // This assumes Actor can be constructed
                                      // using RegularPolygon.
    return 0;
}
