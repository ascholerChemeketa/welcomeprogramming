void deal(CardCollection& that, int n) {
  for (int i = 0; i < n; ++i) {
    if (cards.empty())
      break; // Break if there aren't enough cards
    that.addCard(popCard());
  }
}