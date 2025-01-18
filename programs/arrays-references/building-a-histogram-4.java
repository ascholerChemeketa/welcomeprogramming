int[] counts = new int[100];
for (int i = 0; i &lt; counts.length; i++) {
    counts[i] = inRange(scores, i, i + 1);
}