int search(const vector<Card>& cards, const Card& target) {
  for (size_t i = 0; i < cards.size(); ++i) {
    if (cards[i].equals(target)) {
      return i;
    }
  }
  return -1;
}
