void takeTurn(Player* player) {
  Card prev = discardPile->lastCard();
  Card next = player->play(this, prev);
  discardPile->addCard(next);

  cout << player->getName() << " plays " << next << endl << endl;
}