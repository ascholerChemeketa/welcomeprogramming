public Card searchForMatch(Card prev) {
    for (int i = 0; i &lt; hand.size(); i++) {
        Card card = hand.getCard(i);
        if (cardMatches(card, prev)) {
            return hand.popCard(i);
        }
    }
    return null;
}