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

    bool isEmpty() const {
        return cards.empty();
    }

    void print() const {
        for (const auto& card : cards) {
            cout << card << endl;
        }
    }
};

int main() {
    Pile pile;
    cout << pile.isEmpty() << endl; // prints 1 (true)
    pile.addCard(Card(10, 1));
    cout << pile.isEmpty() << endl; // prints 0 (false)
    return 0;
}