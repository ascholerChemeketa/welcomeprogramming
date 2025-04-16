#include <iostream>
#include <fstream>
#include <format>
#include <string>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Temps.txt");

    if (inFile.fail()) {
        cout << "Could not open file" << endl;
        return 1; // Exit the program with an error code
    }

    string city, state;
    double janTemp, julyTemp, rainfall;

    // Read all five pieces of the first line
    inFile >> city >> state >> janTemp >> julyTemp >> rainfall;
    // Print what we read
    cout << city << " " << state << " " << janTemp << " " << julyTemp << " " << rainfall << endl;
}