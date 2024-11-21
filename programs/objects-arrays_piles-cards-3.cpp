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
class Pile {
private:
  vector<Card> cards;

public:
  Pile() = default;
  void addCard(const Card& card) {
    cards.push_back(card);
  }
  Card popCard() {
    if (cards.empty()) {
      throw runtime_error("Pile is empty");
    }
    Card card = cards.front();
    cards.erase(cards.begin());
    return card;
  }
  void print() const {
    for (const auto& card : cards) {
      cout << card << endl;
    }
  }
};
int main() {
  Pile pile;
  pile.addCard(Card(10, 1));
  pile.addCard(Card(5, 2));
  pile.print();
  return 0;
}