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

    Card& getCard(int index) const {
        return cards[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    const Card* getCards() const {
        return cards;
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

    void addDeck(const Deck& deck) {
        for (int i = 0; i < deck.getSize(); ++i) {
            cards.push_back(deck.getCard(i));
        }
    }

    void print() const {
        for (const auto& card : cards) {
            cout << card << endl;
        }
    }
};

int main() {
    Pile pile;
    Deck deck(5);
    for (int i = 0; i < 5; ++i)
        deck.addCard(Card(i, i));
    pile.addDeck(deck);
    pile.print();
    return 0;
}