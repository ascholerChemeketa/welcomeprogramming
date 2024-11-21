void playGame() {
  Player* player = one.get();

  while (!isDone()) {
    displayState();
    takeTurn(player);
    player = nextPlayer(player);
  }

  one->displayScore();
  two->displayScore();
}