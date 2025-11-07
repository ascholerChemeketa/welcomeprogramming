#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Names.txt");

    while (!inFile.eof()) {
        string name;
        getline(inFile, name); // Read a line from the file and store it into name
        if (inFile.fail()) {
            break;  //oops, too far, exit loop
        }
        cout << "The next name in the file is: " << name << endl;
    }
}

