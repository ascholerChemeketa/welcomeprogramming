#include <iostream>
#include <fstream>
#include <format>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Numbers2.txt");

    // Read 6 numbers
    for (int i = 0; i < 6; i++) {
        int number = 0;
        inFile >> number;
        cout << format("The {}th number in the file is: {}", i, number) << endl;
    }
}

