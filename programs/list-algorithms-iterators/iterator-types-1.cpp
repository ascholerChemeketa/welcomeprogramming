#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    // Create a list of integers
    list<int> numbers = {8, 15, 3, 42, 7};

    sort(numbers.begin(), numbers.end()); // This will cause a compilation error

    // Rely on the list's member sort function
    numbers.sort();

    for (int num : numbers) {
        cout << num << " ";
    }
}