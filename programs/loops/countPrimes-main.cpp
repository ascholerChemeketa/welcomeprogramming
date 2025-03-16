#include <iostream>
using namespace std;


//Paste your isPrime and countPrimes functions here


int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int numPrimes = countPrimes(num);
    cout << "There are " << numPrimes 
         << " primes less than or equal to " << num << endl;
}