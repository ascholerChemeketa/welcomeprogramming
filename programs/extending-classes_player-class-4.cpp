Card* drawForMatch(Eights* eights, const Card& prev) {
  while (true) {
    Card* card = new Card(eights->drawCard());
    cout << name << " draws " << *card << endl;
    if (cardMatches(*card, prev)) {
      return card;
    }
    hand.addCard(*card);
    delete card; // Avoid memory leak
  }
}