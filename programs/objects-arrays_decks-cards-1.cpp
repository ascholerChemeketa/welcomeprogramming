#include <iostream>

class Card {
  public:
    // Add card properties here (suit, rank, etc.)
};

class Deck {
  private:
    Card* cards;
    int capacity;

  public:
    Deck(int n): capacity(n), cards(new Card[n]) {
    }

    ~Deck() {
        delete[] cards;
    }

    Card* getCards() const {
        return cards;
    }

    int getCapacity() const {
        return capacity;
    }
};

int main() {
    Deck deck(52); // Example
    return 0;
}