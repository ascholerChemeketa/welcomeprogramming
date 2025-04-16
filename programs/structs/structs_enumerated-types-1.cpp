#include <iostream>
using namespace std;

enum class Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};


int main() {
    Suit leadSuit = Suit::HEARTS;
    cout << "Lead suit is: ";
    cout << static_cast<int>(leadSuit) << endl;

    cout << "Clubs: " << static_cast<int>(Suit::CLUBS) << endl;
    cout << "Diamonds: " << static_cast<int>(Suit::DIAMONDS) << endl; 
    cout << "Hearts: " << static_cast<int>(Suit::HEARTS) << endl;
    cout << "Spades: " << static_cast<int>(Suit::SPADES) << endl;
}