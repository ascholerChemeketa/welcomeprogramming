#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < a.size(); ++i) {
        a.at(i) = pow(a.at(i), 2); // square each element
    }
    // print the modified vector on one line
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a.at(i) << " ";
    }
}


