public static void printRow(int n, int cols) {
    for (int i = 1; i &lt;= cols; i++) {     // generalized cols
        System.out.printf("%4d", n * i);
    }
    System.out.println();
}