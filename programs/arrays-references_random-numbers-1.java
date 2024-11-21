public static int[] randomArray(int size) {
    Random random = new Random();
    int[] a = new int[size];
    for (int i = 0; i &lt; a.length; i++) {
        a[i] = random.nextInt(100);
    }
    return a;
}