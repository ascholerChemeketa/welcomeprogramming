int test(int r, int c) {
    try {
        if (array[r][c].isOn()) {
            return 1;
        }
    } catch (const out_of_range& e) {
        // cell doesn't exist
    }
    return 0;
}