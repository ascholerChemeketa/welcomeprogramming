private

vector<vector<int>> countNeighbors() {
    int rows = grid->numRows();
    int cols = grid->numCols();

    vector<vector<int>> counts(rows, vector<int>(cols));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            counts[r][c] = countAlive(r, c);
        }
    }
    return counts;
}
