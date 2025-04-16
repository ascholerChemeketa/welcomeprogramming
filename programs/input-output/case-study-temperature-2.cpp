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

    // Print some column headers
    cout << format("{:<20} {:<10} {:<10} {:<10}", "City", "Jan Temp", "July Temp", "Difference") << endl;

    while (!inFile.eof()) {
        // Read in the data
        string city, state;
        double janTemp, julyTemp, rainfall;
        inFile >> city >> state >> janTemp >> julyTemp >> rainfall;
        if (inFile.fail()) {
            break; // Exit the loop if we could not read
        }

        double tempDiff = julyTemp - janTemp;

        // <10.2f means left justify, 10 spaces wide, 2 decimal places
        cout << format("{:<20} {:<10.2f} {:<10.2f} {:<10.2f}", city, janTemp, julyTemp, tempDiff) << endl;
    }
}