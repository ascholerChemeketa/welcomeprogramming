#include <iostream>
class Card {
public:
  int rank;
  int suit;
  Card(int r, int s): rank(r), suit(s) {
  }
  friend ostream& operator<<(ostream& os, const Card& c) {
    os << "(Rank: " << c.rank << ", Suit: " << c.suit << ")";
    return os;
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
  void print() {
    for (int i = 0; i < capacity; ++i) {
      cout << cards[i] << endl;
    }
  }
};
int main() {
  Deck deck;
  deck.print();
  return 0;
}