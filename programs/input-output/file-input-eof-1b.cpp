#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Numbers.txt");

    while (!inFile.eof()) {
        int number;
        inFile >> number;
        if (inFile.fail()) {
            break;  //oops, too far, exit loop
        }
        cout << "The next number in the file is: " << number << endl;
    }
    cout << "Reached the end of the file." << endl;
}

