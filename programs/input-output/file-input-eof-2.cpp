#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Names.txt");

    while (!inFile.eof()) {
        string name;
        inFile >> name;
        cout << "The next number in the file is: " << name << endl;
    }
}

