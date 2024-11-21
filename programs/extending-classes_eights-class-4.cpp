Card drawCard() {
  if (drawPile->isEmpty()) {
    reshuffle();
  }
  if (drawPile->isEmpty())
    return Card{}; // Return a default constructed Card if the drawPile is empty
                   // after reshuffling
  return drawPile->popCard();
}