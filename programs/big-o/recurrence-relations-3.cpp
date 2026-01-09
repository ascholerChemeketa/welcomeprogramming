int mystery(int n) {
    if (n <= 1) {
        // O(1) work
    } else {
        // O(n) work
        for (int i = 0; i < n; i++)...

        // Two recursive calls
        mystery(n / 2);
        mystery(n / 2);

        // O(1) work
    }
}