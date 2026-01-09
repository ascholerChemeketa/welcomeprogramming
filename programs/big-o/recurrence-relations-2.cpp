int mystery(int n) {
    if (n <= 1) {
        // O(1) work
    } else {
        mystery(n / 2);
        // O(1) work
    }
}