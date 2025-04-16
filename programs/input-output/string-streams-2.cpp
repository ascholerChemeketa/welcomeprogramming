#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string data = "10 20 30 40 50";

    // Create a stringstream object
    stringstream fakeFile;
    // Initialize the stringstream with string to read
    fakeFile.str(data);

    // Now read as if it were a file
    while (!fakeFile.eof()) {
        int number;
        fakeFile >> number; // Read the next number from the stringstream
        if (fakeFile.fail()) {
            break; // Exit the loop if we could not read
        }
        cout << "The next number is: " << number << endl;
    }
}