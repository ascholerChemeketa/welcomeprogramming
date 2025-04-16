#include <iostream>
#include <string>
#include <exception>
using namespace std;

enum class Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

string suitToString(Suit s) {
    switch (s) {
        case Suit::CLUBS: return "Clubs";
        case Suit::DIAMONDS: return "Diamonds";
        case Suit::HEARTS: return "Hearts";
        case Suit::SPADES: return "Spades";
        default: throw logic_error("Invalid suit value");
    }
}

// Returns the dominant suit between two suits
// The dominant suit is the one with the higher value
Suit dominantSuit(Suit s1, Suit s2) {
    if (s1 > s2) {
        return s1;
    } else {
        return s2;
    }
}

int main() {
    Suit mySuit = Suit::HEARTS;
    Suit theirSuit = Suit::DIAMONDS;

    Suit leadSuit = dominantSuit(mySuit, theirSuit);
    cout << "Lead suit is: " << suitToString(leadSuit) << endl;
}
