public static int banana(int[] a) {
    int kiwi = 1;
    int i = 0;
    while (i &lt; a.length) {
        kiwi = kiwi * a[i];
        i++;
    }
    return kiwi;
}