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

    void selectionSort() {
        for (int i = 0; i < capacity - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < capacity; ++j) {
                if (cards[j] < cards[minIndex]) {
                    minIndex = j;
                }
            }
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