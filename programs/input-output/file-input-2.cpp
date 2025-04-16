#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Create the variable AND open the file
    ifstream inFile("Numbers.txt");
    // Same as 
    // ifstream inFile;
    // inFile.open("Numbers.txt");

    if (inFile.fail()) {
        cout << "Could not open file" << endl;
        // exit the program with an error code
        return 1;
    }

    // File must be open if we reach this point
    int number = 0;
    inFile >> number;

    cout << "The first number in the file is: " << number << endl;
}