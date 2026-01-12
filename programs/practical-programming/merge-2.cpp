#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {3, 7, 2, 9};

    int sum = accumulate(
        nums.begin(),
        nums.end(),
        0,  // initial value is 0 for sum
        [](int a, int b) { return a + b; }
    );

    cout << "Sum: " << sum << endl;
}