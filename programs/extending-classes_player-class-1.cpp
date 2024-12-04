class Player {
  public:
    string name;
    Hand hand;

    Player(const string& name): name(name), hand(name) {
    }

    string getName() const {
        return name;
    }

    Hand& getHand() {
        return hand;
    }

    void addCard(const Card& card) {
        hand.addCard(card);
    }

    void display() const {
        hand.display();
    }

    void displayScore() const {
        cout << name << " has " << hand.size() << " cards.";
    }

    Card play(Eights* game, const Card& prev) {
        // To be implemented
        return Card();
    }
};