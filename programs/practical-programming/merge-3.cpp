#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {3, 7, 2, 9};

    int product = accumulate(
        nums.begin(),
        nums.end(),
        1,  // initial value is 1 for product
        // operation to accumulate with
        std::multiplies<int>()
        // or define multiply ourselves as a lamba:
        // [](int a, int b) { return a * b; }
    );

    cout << "Product: " << product << endl;
}