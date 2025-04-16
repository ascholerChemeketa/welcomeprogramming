#include <iostream>
#include <fstream>
#include <format>
#include <string>
using namespace std;

int main() {
    ifstream inFile;
    inFile.open("Cars.txt");

    while( !inFile.eof() ) {
      string make, model;
      int year;
      inFile >> make >> model >> year;
      if (inFile.fail()) {
          break; // Exit the loop if we could not read
      }
      cout << format("The next car is a {} {} {}", year, make, model) << endl;
  }
}