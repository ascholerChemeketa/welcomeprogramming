#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};

    for (size_t i = 0; i < a.size(); ++i) {
        int oldValue = a.at(i);
        int newValue = oldValue * oldValue;
        a.at(i) = newValue; // set the new value at index i
    }

    // print the modified vector on one line
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a.at(i) << " ";
    }
}


