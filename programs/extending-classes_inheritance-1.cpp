class Card {
public:
  int rank;
  int suit;

  Card(int rank, int suit): rank(rank), suit(suit) {
  }
};

class Deck : public CardCollection {
public:
  Deck(const string& label): CardCollection(label) {
    for (int suit = 0; suit <= 3; ++suit) {
      for (int rank = 1; rank <= 13; ++rank) {
        addCard(Card(rank, suit));
      }
    }
  }
};