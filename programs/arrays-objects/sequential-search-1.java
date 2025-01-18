public static int search(Card[] cards, Card target) {
    for (int i = 0; i &lt; cards.length; i++) {
        if (cards[i].equals(target)) {
            return i;
        }
    }
    return -1;
}