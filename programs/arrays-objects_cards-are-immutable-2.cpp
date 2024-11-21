#include <string>

class Card {
private:
  const int rank;
  const int suit;

public:
  Card(int rank, int suit): rank(rank), suit(suit) {
  }
  int compareTo(const Card& other) const {
    if (this->suit != other.suit)
      return this->suit - other.suit;
    return this->rank - other.rank;
  }
  friend ostream& operator<<(ostream& os, const Card& card) {
    string ranks[] = {"invalid", "A", "2", "3", "4", "5", "6",
                           "7",       "8", "9", "T", "J", "Q", "K"};
    string suits[] = {"invalid", "C", "D", "H", "S"};
    os << ranks[card.rank] << suits[card.suit];
    return os;
  }
  int getRank() const {
    return rank;
  }
  int getSuit() const {
    return suit;
  }
};
