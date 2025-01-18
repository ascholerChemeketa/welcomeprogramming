for (int r = 0; r < rows; ++r) {
    int y = r * size;
    for (int c = 0; c < cols; ++c) {
        int x = c * size;
        array[r][c] = Cell(x, y, size);
    }
}
