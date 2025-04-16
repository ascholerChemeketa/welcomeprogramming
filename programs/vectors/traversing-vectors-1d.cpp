#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    for (int& value : a) {
      value = value * 2; // double each element
    }
    // print the modified vector on one line
    for (int value : a) {
        cout << value << " ";
    }
}