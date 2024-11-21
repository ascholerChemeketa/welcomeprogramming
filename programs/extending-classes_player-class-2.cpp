Card play(Eights* eights, const Card& prev) {
  Card* card = searchForMatch(prev);
  if (card == nullptr) {
    card = drawForMatch(eights, prev);
  }
  if (card == nullptr)
    return Card(); // Return a default constructed card if no card can be played
  hand.popCard(distance(hand.cards.begin(),
                        card)); // Remove the card from the player's hand
  return *card;
}