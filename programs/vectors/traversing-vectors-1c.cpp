#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    for (int value : numbers) {
        cout << value << " ";
    }
    cout << endl;
    vector<double> temps = {74.2, 78.6, 80.1, 82.5, 85.0};
    for (double t : temps) {
        cout << t << " ";
    }
}


