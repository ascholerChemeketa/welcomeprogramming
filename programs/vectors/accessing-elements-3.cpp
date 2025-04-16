#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> counts = {12, 6, 3, 14};

    counts.at(0) = 7;
    counts.at(1) = counts.at(0) * 2;
    ++counts.at(2);
    counts.at(3) -= 6;

    cout << counts.at(0) << endl;
    cout << counts.at(1) << endl;
    cout << counts.at(2) << endl;
    cout << counts.at(3) << endl;
    // uh-oh, this will cause an error
    cout << counts.at(4) << endl;
}