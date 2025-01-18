public static int grapefruit(int[] a, int grape) {
    for (int i = 0; i &lt; a.length; i++) {
        if (a[i] == grape) {
            return i;
        }
    }
    return -1;
}