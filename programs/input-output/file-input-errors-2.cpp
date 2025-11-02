#include <iostream>
#include <fstream>
#include <format>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Numbers2.txt");

    // Read 6 numbers
    for (int i = 0; i < 6; ++i) {
        int number = 0;
        inFile >> number;
        if (inFile.fail()) {
            cout << "Error reading number " << i << endl;
            break; // Exit the loop if there is an error
        }
        cout << format("The {}th number in the file is: {}", i, number) << endl;
    }
}

