#include <iostream>
using namespace std;

int main() {
    int height = 68;
    int feet = height / 12;   // quotient
    int inches = height % 12; // remainder
    cout << "The person is " << feet << " feet " << inches << " inch(es) tall.";
}
