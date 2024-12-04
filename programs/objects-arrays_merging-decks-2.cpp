#include <algorithm>
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

    void selectionSort() {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (cards[j] < cards[minIndex]) {
                    minIndex = j;
                }
            }
            swap(cards[i], cards[minIndex]);
        }
    }

    Deck almostMergeSort() {
        if (size <= 1)
            return *this;
        int mid = size / 2;
        Deck left(mid);
        Deck right(size - mid);
        for (int i = 0; i < mid; ++i)
            left.addCard(cards[i]);
        for (int i = mid; i < size; ++i)
            right.addCard(cards[i]);
        left.selectionSort();
        right.selectionSort();
        return Deck::merge(left, right);
    }

    static Deck merge(const Deck& d1, const Deck& d2) {
        Deck d3(d1.getSize() + d2.getSize());
        int i = 0, j = 0, k = 0;
        while (i < d1.getSize() && j < d2.getSize()) {
            if (d1.getCard(i) < d2.getCard(j)) {
                d3.addCard(d1.getCard(i++));
            } else {
                d3.addCard(d2.getCard(j++));
            }
        }
        while (i < d1.getSize())
            d3.addCard(d1.getCard(i++));
        while (j < d2.getSize())
            d3.addCard(d2.getCard(j++));
        return d3;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << cards[i] << endl;
        }
    }
};

int main() {
    Deck deck(52);
    int index = 0;
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            deck.addCard(Card(rank, suit));
        }
    }
    deck = deck.almostMergeSort();
    deck.print();
    return 0;
}