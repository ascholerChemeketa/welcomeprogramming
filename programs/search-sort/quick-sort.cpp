#include <iostream>
#include <vector>
using namespace std;

#include "vector-helpers.h"

// Other helpers (defined below main)
template<typename T>
int partition(vector<T>& vec, int start, int end);

string spaces(bool add = true, bool remove = false);

// Recursive quick sort function
template<typename T>
void quickSort(vector<T>& vec, int start, int end) {
    if (start >= end) {
        return; // Base case: 0-1 items are already sorted
    }
    // Debug output
    cout << spaces() << "quickSort called with start=" << start << ", end=" << end << endl;
    cout << spaces(false) << vectorToString(vec, start, end) << endl;
    
    int pivotIndex = partition(vec, start, end);           // Partition the two halves

    quickSort(vec, start, pivotIndex - 1);       // Sort left half
    quickSort(vec, pivotIndex + 1, end);     // Sort right half
    
    // Debug output
    cout << spaces(false) << "quickSort ending start=" << start << ", end=" << end << endl;
    cout << spaces(false) << vectorToString(vec, start, end) << endl;
    spaces(false, true);
}

// Wrapper function to initiate quick sort
template<typename T>
void quickSort(vector<T>& vec) {
    // Do the sort
    quickSort(vec, 0, vec.size() - 1);
}


int main() {
    vector<int> numbers = {8, 3, 7, 1, 9, 12, 20, 6, 11, 14, 2, 16, 4, 10, 5, 15};
    quickSort(numbers);
    cout << "Sorted array: " << endl;
    cout << vectorToString(numbers) << endl;
}




// Partition the vector segment from start to end
// returns the final index of the pivot
template<typename T>
int partition(vector<T>& vec, int start, int end) {
    T pivotValue = vec.at(start);
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
            // advance i and retreat j since those items are fixed
            i++;
            j--;
        }
    }
    // j will always have the final pivot position
    swap(vec.at(start), vec.at(j));
    return j;
}


// Manage indentation for debug output
string spaces(bool add, bool remove) {
  static string spaces = "";
  if (add) {
      string curSpaces = spaces;
      spaces += " ";
      return curSpaces;
  }
  if (remove) {
      spaces.pop_back();
  }
  return spaces;
}