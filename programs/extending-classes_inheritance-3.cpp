class Hand : public CardCollection {
public:
  Hand(const string& label): CardCollection(label) {
  }
  void display() const {
    cout << getLabel() << ":\n";
    for (size_t i = 0; i < cards.size(); ++i) {
      cout << cards[i].rank << " of ";
      switch (cards[i].suit) {
      case 0:
        cout << "Clubs";
        break;
      case 1:
        cout << "Diamonds";
        break;
      case 2:
        cout << "Hearts";
        break;
      case 3:
        cout << "Spades";
        break;
      }
      cout << "\n";
    }
    cout << "\n";
  }
};