#include <iostream>

class Card {
public:
  int rank;
  int suit;

  Card(int r, int s): rank(r), suit(s) {
  }
};

class Deck {
private:
  Card* cards;
  int capacity = 52;

public:
  Deck(): cards(new Card[capacity]) {
    int index = 0;
    for (int suit = 0; suit <= 3; suit++) {
      for (int rank = 1; rank <= 13; rank++) {
        cards[index++] = Card(rank, suit);
      }
    }
  }

  ~Deck() {
    delete[] cards;
  }

  Card* getCards() const {
    return cards;
  }
};

int main() {
  Deck deck;
  return 0;
}