#include <iostream>
#include <vector>
using namespace std;

#include "vector-helpers.h"

// Partition the vector segment from start to end
// returns the final index of the pivot
template<typename T>
int partition(vector<T>& vec, int start, int end) {
    T pivotValue = vec.at(start);
    cout << "Using pivot value: " << pivotValue << " at index " << start
         << endl;
    int i = start + 1;
    int j = end;
    while (i <= j) {
        // Move i right until it finds something that belongs on the right
        while (i <= end && vec.at(i) <= pivotValue) {
            i++;
        }
        // Move j left until it finds something that belongs on the left
        while (j >= start && vec.at(j) > pivotValue) {
            j--;
        }
        // Swap items at i and j if i < j
        if (i < j) {
            swap(vec.at(i), vec.at(j));
            cout << "Swapped " << vec.at(i) << " and " << vec.at(j) << endl;
            cout << vectorToString(vec, start, end) << endl;
            // advance i and retreat j since those items are fixed
            i++;
            j--;
        }
    }
    // j will always have the final pivot position
    swap(vec.at(start), vec.at(j));
    cout << "Finish by swapping " << vec.at(start) << " (start) and "
         << vec.at(j) << " (j)" << endl;
    cout << vectorToString(vec, start, end) << endl;
    return j;
}

int main() {
    vector<int> numbers = {0, 0, 7, 1, 8, 3, 15, 4, 9, 2, 0, 0};
    int start = 2;
    int end = 9;
    cout << "Partitioning array: " << endl;
    cout << vectorToString(numbers, start, end) << endl;
    cout << "  using range " << start << " to " << end << endl;
    int pivotIndex = partition(numbers, start, end);
    cout << "Pivot final index: " << pivotIndex << endl;
}