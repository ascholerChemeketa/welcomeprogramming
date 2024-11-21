public static void printRow(int n) {
    for (int i = 1; i &lt;= 6; i++) {
        System.out.printf("%4d", n * i);  // generalized n
    }
    System.out.println();
}