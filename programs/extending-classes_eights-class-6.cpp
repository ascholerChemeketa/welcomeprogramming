void displayState() {
  one->display();
  two->display();
  discardPile->display();
  cout << "Draw pile:\n";
  cout << drawPile->size() << " cards\n";
  string dummy;
  getline(cin, dummy);
}
