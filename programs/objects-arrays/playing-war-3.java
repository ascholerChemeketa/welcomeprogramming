while (!p1.isEmpty() &amp;&amp; !p2.isEmpty()) {
    // pop a card from each pile
    Card c1 = p1.popCard();
    Card c2 = p2.popCard();

    // compare the cards
    int diff = c1.getRank() - c2.getRank();
    if (diff > 0) {
        p1.addCard(c1);
        p1.addCard(c2);
    } else if (diff &lt; 0) {
        p2.addCard(c1);
        p2.addCard(c2);
    } else {
        // it's a tie
    }