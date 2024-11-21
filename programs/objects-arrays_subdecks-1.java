public Deck subdeck(int low, int high) {
    Deck sub = new Deck(high - low + 1);
    for (int i = 0; i &lt; sub.cards.length; i++) {
        sub.cards[i] = this.cards[low + i];
    }
    return sub;
}