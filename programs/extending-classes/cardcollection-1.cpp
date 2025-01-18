#include <string>
#include <vector>

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
};