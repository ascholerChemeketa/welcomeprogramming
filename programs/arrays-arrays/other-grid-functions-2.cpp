Cell& getCell(int r, int c) {
    return array[r][c];
}

void turnOn(int r, int c) {
    array[r][c].turnOn();
}
