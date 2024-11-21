class GridCanvas : public Canvas {
private:
  vector<vector<Cell>> array;

public:
  GridCanvas(int rows, int cols, int size) {
    array.resize(rows, vector<Cell>(cols));
    for (int r = 0; r < rows; r++) {
      int y = r * size;
      for (int c = 0; c < cols; c++) {
        int x = c * size;
        array[r][c] = Cell(x, y, size);
      }
    }

    // set the canvas size
    setSize(cols * size, rows * size);
  }
};