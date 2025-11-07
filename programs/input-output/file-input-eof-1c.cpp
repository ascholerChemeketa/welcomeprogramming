#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Numbers.txt");

    int number;
    // while we successfully read in a number
    while (inFile >> number) {
        cout << "The next number in the file is: " << number << endl;
    }
    cout << "Reached the end of the file." << endl;
}

