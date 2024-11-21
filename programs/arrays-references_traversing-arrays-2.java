public static int search(double[] array, double target) {
    for (int i = 0; i &lt; array.length; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;  // not found
}