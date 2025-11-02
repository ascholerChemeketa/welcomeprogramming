#include <iostream>
#include <string>

using namespace std;

int main() {
    // Allocate an array of 4 integers
    int* data = new int[3];
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;

    // Make a new empty array:
    int* copy = new int[3];

    // Copy the contents of data to copy
    for (int i = 0; i < 3; ++i) {
        copy[i] = data[i];
    }

    // Delete the arrays
    delete[] data;
    delete[] copy;
}