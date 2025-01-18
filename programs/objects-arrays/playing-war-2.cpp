#include <algorithm>
#include <iostream>
#include <random>
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
};

class Pile {
  private:
    vector<Card> cards;

  public:
    Pile() = default;

    void addCard(const Card& card) {
        cards.push_back(card);
    }

    void addDeck(const Deck& deck) {
        cards.insert(cards.end(), deck.cards.begin(), deck.cards.end());
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
    Deck deck(52);
    deck.shuffle();
    Pile p1;
    p1.addDeck(deck.subdeck(0, 25));
    Pile p2;
    p2.addDeck(deck.subdeck(26, 51));
    p1.print();
    cout << "-----\n";
    p2.print();
    return 0;
}