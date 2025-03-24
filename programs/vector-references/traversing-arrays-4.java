public static double sum(double[] array) {
    double total = 0.0;
    for (int i = 0; i &lt; array.length; i++) {
        total += array[i];
    }
    return total;
}