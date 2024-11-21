#include <algorithm>
#include <iostream>
#include <random>

class Card {
public:
  // Add Card members here
};

class CardCollection {
private:
  string label;
  vector<Card> cards;

public:
  CardCollection(const string& label): label(label) {
  }

  void swapCards(int i, int j) {
    swap(cards[i], cards[j]);
  }

  void shuffle() {
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
  }

  void addCard(const Card& card) {
    cards.push_back(card);
  }

  Card popCard(int i) {
    Card c = cards[i];
    cards.erase(cards.begin() + i);
    return c;
  }

  Card popCard() {
    if (cards.empty())
      return Card();
    Card c = cards.back();
    cards.pop_back();
    return c;
  }

  bool isEmpty() const {
    return cards.empty();
  }

  int size() const {
    return cards.size();
  }

  Card getCard(int i) const {
    return cards[i];
  }

  Card lastCard() const {
    if (cards.empty())
      return Card();
    return cards.back();
  }

  void deal(CardCollection& that, int n) {
    for (int i = 0; i < n; ++i) {
      if (cards.empty())
        break;
      that.addCard(popCard());
    }
  }

  void dealAll(CardCollection& that) {
    deal(that, cards.size());
  }

  // Add display function
};

int main() {
  // Assume Deck and Hand are subclasses of CardCollection
  Deck deck("Deck");
  deck.shuffle();

  Hand hand("Hand");
  deck.deal(hand, 5);
  hand.display();

  Hand drawPile("Draw Pile");
  deck.dealAll(drawPile);
  printf("Draw Pile has %d cards.\n", drawPile.size());
  return 0;
}
