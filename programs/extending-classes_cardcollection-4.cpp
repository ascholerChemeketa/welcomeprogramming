Card popCard(int i) {
  Card c = cards[i];
  cards.erase(cards.begin() + i);
  return c;
}