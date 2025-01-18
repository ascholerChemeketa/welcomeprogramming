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
        for (int suit = 0; suit <= 3; suit++) {
            for (int rank = 1; rank <= 13; rank++) {
                cards.emplace_back(rank, suit);
            }
        }
    }

    void print() const {
        for (const auto& card : cards) {
            cout << card << endl;
        }
    }
};

int main() {
    Deck deck(52);
    deck.print();
    return 0;
}