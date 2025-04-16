#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Numbers.txt");

    while (!inFile.eof()) {
        int number;
        inFile >> number;
        cout << "The next number in the file is: " << number << endl;
    }
}

