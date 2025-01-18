public void deal(CardCollection that, int n) {
    for (int i = 0; i &lt; n; i++) {
        Card card = popCard();
        that.addCard(card);
    }
}