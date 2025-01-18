private int[][] countNeighbors() {
    int rows = grid.numRows();
    int cols = grid.numCols();

    int[][] counts = new int[rows][cols];
    for (int r = 0; r &lt; rows; r++) {
        for (int c = 0; c &lt; cols; c++) {
            counts[r][c] = countAlive(r, c);
        }
    }
    return counts;
}