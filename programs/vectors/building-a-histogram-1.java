public static int inRange(int[] a, int low, int high) {
    int count = 0;
    for (int i = 0; i &lt; a.length; i++) {
        if (a[i] >= low &amp;&amp; a[i] &lt; high) {
            count++;
        }
    }
    return count;
}