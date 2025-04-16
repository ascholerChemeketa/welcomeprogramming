#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a 2D vector (3x4) and initialize it
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Traverse the matrix using range-based for loop
    cout << "Matrix elements:" << endl;
    // get the number of rows
    size_t rowCount = matrix.size();
    // get the size of the first row... assumes all rows are the same
    size_t colCount = matrix.at(0).size();

    // loop through the rows
    for (size_t row = 0; row < rowCount; ++row) {
        // loop through the columns
        for (size_t col = 0; col < colCount; ++col) {
            cout << matrix.at(row).at(col) << " ";
        }
        cout << endl;
    }
}