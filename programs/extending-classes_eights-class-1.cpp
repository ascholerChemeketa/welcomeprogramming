#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

// Forward declarations
class Player;
class Hand;

class Eights {
public:
  Eights(shared_ptr<Player> p1, shared_ptr<Player> p2);

private:
  shared_ptr<Player> one;
  shared_ptr<Player> two;
  shared_ptr<Hand> drawPile;
  shared_ptr<Hand> discardPile;
};

// Implement the Eights constructor
Eights::Eights(shared_ptr<Player> p1, shared_ptr<Player> p2):
    one(p1), two(p2) {
  // Initialize drawPile and discardPile here
}

// other classes would be implemented here