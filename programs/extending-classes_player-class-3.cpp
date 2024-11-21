Card* searchForMatch(const Card& prev) {
  for (size_t i = 0; i < hand.cards.size(); ++i) {
    if (cardMatches(hand.cards[i], prev)) {
      return &hand.cards[i];
    }
  }
  return nullptr;
}