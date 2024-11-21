for (int r = 0; r &lt; rows; r++) {
    int y = r * size;
    for (int c = 0; c &lt; cols; c++) {
        int x = c * size;
        array[r][c] = new Cell(x, y, size);
    }
}