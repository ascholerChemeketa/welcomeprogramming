Player* nextPlayer(Player* current) {
  return (current == one.get()) ? two.get() : one.get();
}