#include <iostream>
#include <format>
using namespace std;

int myHash(double value) {
  return bit_cast<uint64_t>(value);
    return static_cast<int>(value * 10000);
}

int main() {
    double value = 3.14;
    int hashValue = myHash(value);
    cout << "Hash of " << value << " is: " << hashValue << endl;

    
    double value2 = 3.01;
    int hashValue2 = myHash(value2);
    cout << "Hash of " << value2 << " is: " << hashValue2 << endl;

    double value3 = 3.0999999999999996;
    int hashValue3 = myHash(value3);
    cout << "Hash of " << format("{:.16f}", value3) << " is: " << hashValue3 << endl;
}