/*This function merges two sorted decks into a single sorted deck.*/
#include <iostream>

class Card {
  public:
    int rank;
    int suit;

    Card(int r, int s): rank(r), suit(s) {
    }

    friend bool operator<(const Card& a, const Card& b) {
        return a.rank < b.rank; // Sort by rank.  Modify if needed
    }

    friend ostream& operator<<(ostream& os, const Card& c) {
        os << "(Rank: " << c.rank << ", Suit: " << c.suit << ")";
        return os;
    }
};

class Deck {
  private:
    Card* cards;
    int capacity;
    int size = 0;

  public:
    Deck(int n): capacity(n), cards(new Card[n]) {
    }

    Deck(const Deck& other):
        capacity(other.capacity), cards(new Card[capacity]), size(other.size) {
        for (int i = 0; i < size; ++i)
            cards[i] = other.cards[i];
    }

    Deck& operator=(const Deck& other) {
        if (this != &other) {
            delete[] cards;
            capacity = other.capacity;
            cards = new Card[capacity];
            size = other.size;
            for (int i = 0; i < size; ++i)
                cards[i] = other.cards[i];
        }
        return *this;
    }

    ~Deck() {
        delete[] cards;
    }

    void addCard(const Card& card) {
        if (size < capacity)
            cards[size++] = card;
    }

    Card& getCard(int index) {
        return cards[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    static Deck merge(const Deck& d1, const Deck& d2) {
        Deck d3(d1.getSize() + d2.getSize());
        int i = 0, j = 0, k = 0;
        while (i < d1.getSize() && j < d2.getSize()) {
            if (d1.getCard(i) < d2.getCard(j)) {
                d3.addCard(d1.getCard(++i));
            } else {
                d3.addCard(d2.getCard(++j));
            }
        }
        while (i < d1.getSize())
            d3.addCard(d1.getCard(++i));
        while (j < d2.getSize())
            d3.addCard(d2.getCard(++j));
        return d3;
    }
};

int main() {
    return 0;
}