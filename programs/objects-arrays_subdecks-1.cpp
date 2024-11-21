#include <iostream>
#include <vector>

class Card {
public:
  int rank;
  int suit;

  Card(int r, int s): rank(r), suit(s) {
  }

  friend bool operator<(const Card& a, const Card& b) {
    return a.rank < b.rank;
  }

  friend ostream& operator<<(ostream& os, const Card& c) {
    os << "(Rank: " << c.rank << ", Suit: " << c.suit << ")";
    return os;
  }
};

class Deck {
private:
  vector<Card> cards;
  int size = 0;

public:
  Deck(int n): size(n) {
    cards.reserve(n);
  }

  Deck subdeck(int start, int end) const {
    Deck sub(end - start + 1);
    for (int i = start; i <= end; ++i) {
      sub.cards.push_back(cards[i]);
    }
    return sub;
  }

  void shuffle() {
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
  }

  void print() const {
    for (const auto& card : cards) {
      cout << card << endl;
    }
  }

  int getSize() const {
    return size;
  }

  void addCard(const Card& card) {
    cards.push_back(card);
  }

  const Card* getCards() const {
    return cards.data();
  }

  int randomInt(int low, int high) const {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(low, high);
    return distrib(gen);
  }

  void swapCards(int i, int j) {
    swap(cards[i], cards[j]);
  }

  static Deck merge(const Deck& d1, const Deck& d2) {
    Deck d3(d1.cards.size() + d2.cards.size());
    int i = 0, j = 0, k = 0;
    while (i < d1.cards.size() && j < d2.cards.size()) {
      if (d1.cards[i] < d2.cards[j]) {
        d3.cards.push_back(d1.cards[i++]);
      } else {
        d3.cards.push_back(d2.cards[j++]);
      }
    }
    while (i < d1.cards.size())
      d3.cards.push_back(d1.cards[i++]);
    while (j < d2.cards.size())
      d3.cards.push_back(d2.cards[j++]);
    return d3;
  }
};

int main() {
  Deck deck(52);
  for (int i = 0; i < 52; ++i)
    deck.addCard(Card(i % 13 + 1, i / 13));
  Deck sub = deck.subdeck(0, 25);
  for (int i = 0; i < sub.cards.size(); ++i)
    cout << sub.cards[i] << endl;
  return 0;
}