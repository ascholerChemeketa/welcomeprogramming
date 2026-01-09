int factorial(int n) {
    if (n <= 1) {
        // O(1) work
        return 1;
    } else {
        // time for factorial(n - 1)
        // O(1) work to multiple and return
        return n * factorial(n - 1);
    }
}