#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    remove_if(
        nums.begin(),
        nums.end(),
        // Lambda function to identify even numbers
        [](int n) { return n % 2 == 0; }
    );

    for (const auto& num : nums) {
        cout << num << " ";
    }
}