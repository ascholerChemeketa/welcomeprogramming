#include <iostream>
using namespace std;

int main() {
    int hour = 11;
    int minute = 59;
    int totalMinutes = hour * 60 + minute;
    cout << "Number of minutes since midnight: " << totalMinutes << endl;
}