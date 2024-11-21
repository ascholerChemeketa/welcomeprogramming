void reshuffle() {
  if (discardPile->isEmpty())
    return;
  Card prev = discardPile->popCard();
  discardPile->dealAll(*drawPile);
  discardPile->addCard(prev);
  drawPile->shuffle();
}