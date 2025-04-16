#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Numbers.txt");

    int number = 0;
    inFile >> number;
    cout << "The first number in the file is: " << number << endl;

    inFile >> number;
    cout << "The first number in the file is: " << number << endl;
}

