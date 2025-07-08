int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        // get answer, then multiply by n before returning
        return n * factorial(n - 1);
    }
}