#include <iostream>
using namespace std;

int main() {
    int hour = 11;
    int minute = 59;
    cout << hour;
    cout << ":";
    cout << minute;
    cout << endl; // end the first line of output
    // now print the same thing using only one cout statement
    cout << hour << ":" << minute << endl;
}