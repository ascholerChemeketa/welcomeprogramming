/*This code is incomplete and contains a syntax error because printTwice is not
 * defined.  To fix it, you would need to define a function called printTwice
 * that takes an integer as input and prints it twice.*/
#include <iostream>
using namespace std;

// Define the printTwice function
void printTwice(int num) {
  cout << num << " ";
  cout << num << endl;
}

int main() {
  printTwice(17); // This will now work
  return 0;
}