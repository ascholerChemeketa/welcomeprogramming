#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> counts = {12, 6, 3, 14};

    // set first element to 7
    counts.at(0) = 7;
    // set second element to twice the first
    counts.at(1) = counts.at(0) * 2;
    // increment the third element
    ++counts.at(2);
    // reduce the fourth element by 6
    counts.at(3) -= 6;

    cout << counts.at(0) << endl;
    cout << counts.at(1) << endl;
    cout << counts.at(2) << endl;
    cout << counts.at(3) << endl;
    // uh-oh, this will cause an error
    cout << counts.at(4) << endl;
}