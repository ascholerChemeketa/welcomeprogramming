#include <iostream>
#include <vector>
using namespace std;

void printMaze(const vector<vector<char>>& curMaze) {
    size_t rows = curMaze.size();
    size_t cols = curMaze.at(0).size();
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            cout << curMaze.at(r).at(c);
        }
        cout << endl;
    }
    cout << endl << endl;
}