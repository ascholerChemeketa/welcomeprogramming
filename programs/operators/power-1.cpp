#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    vector<int> numbers = {5, 3, 8, 1, 4};

    // Sort the vector in ascending order
    sort(numbers.begin(), numbers.end());

    // Print the sorted vector
    cout << "Sorted numbers: ";
    for (const int& num : numbers) {
        cout << num << " ";
    }
}