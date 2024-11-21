#include <string>

class Card {
public:
  static const vector<string> RANKS;
  static const vector<string> SUITS;

private:
  const int rank;
  const int suit;

public:
  Card(int rank, int suit): rank(rank), suit(suit) {
  }
  friend ostream& operator<<(ostream& os, const Card& card) {
    os << Card::RANKS[card.rank] << " of " << Card::SUITS[card.suit];
    return os;
  }
  int getRank() const {
    return rank;
  }
  int getSuit() const {
    return suit;
  }
};
const vector<string> Card::RANKS = {
    "invalid", "Ace", "2", "3",  "4",    "5",     "6",
    "7",       "8",   "9", "10", "Jack", "Queen", "King"};
const vector<string> Card::SUITS = {"Clubs", "Diamonds", "Hearts",
                                              "Spades"};
