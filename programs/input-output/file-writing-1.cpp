#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile;
    outFile.open("data.txt");

    if (!outFile) {
        cout << "Error opening file" << endl;
        return 1; // Exit the program with an error code
    }

    for (int i = 1; i <= 5; ++i) {
        // Write the numbers 1 to 5 to the file
        outFile << i << endl;
    }

    outFile.close(); // Close the file after writing
    cout << "Data written to file successfully." << endl;

    ifstream inFile;
    inFile.open("data.txt");
    for (int i = 1; i <= 5; ++i) {
        int number;
        inFile >> number; // Read the numbers from the file
        cout << "Number " << i << ": " << number << endl;
    }
}