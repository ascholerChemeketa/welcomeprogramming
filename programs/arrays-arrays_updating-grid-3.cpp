private
void updateGrid(const vector<vector<int>>& counts) {
  int rows = grid->numRows();
  int cols = grid->numCols();

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      Cell& cell = grid->getCell(r, c);
      updateCell(cell, counts[r][c]);
    }
  }
}
