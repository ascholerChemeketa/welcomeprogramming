#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    stringstream fakeFile;

    string type = "Toyota Camry";
    int year = 2020;
    // Write to the stringstream
    fakeFile << type << " " << year << endl;
    fakeFile << "Honda Accord" << 2019 << endl;

    // Get the string from the stringstream
    string output = fakeFile.str();
    cout << "The string from the stringstream is: " << endl
         << output << endl;
}