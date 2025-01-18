int pow(int x, int n) {
    if (n == 0)
        return 1;

    int t = pow(x, n / 2);

    if (n % 2 == 0) {
        return t * t;
    } else {
        return t * t * x;
    }
}