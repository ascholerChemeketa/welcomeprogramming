#include <iostream>
#include <vector>
using namespace std;

void printMaze(const vector<vector<char>>& curMaze) {
    int rows = curMaze.size();
    int cols = curMaze.at(0).size();
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << curMaze.at(r).at(c);
        }
        cout << endl;
    }
    cout << endl << endl;
}