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

    int indexLowest(int low, int high) {
        int minIndex = low;
        for (int i = low + 1; i <= high; ++i) {
            if (cards[i] < cards[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }

    void selectionSort() {
        for (int i = 0; i < capacity - 1; ++i) {
            int minIndex = indexLowest(i, capacity - 1);
            swap(cards[i], cards[minIndex]);
        }
    }

    void print() {
        for (int i = 0; i < capacity; ++i) {
            cout << cards[i] << endl;
        }
    }
};

int main() {
    Deck deck;
    deck.selectionSort();
    deck.print();
    return 0;
}