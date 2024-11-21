string toString() const {
  vector<string> ranks = {"invalid", "Ace",  "2",     "3",   "4",
                                    "5",       "6",    "7",     "8",   "9",
                                    "10",      "Jack", "Queen", "King"};
  vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
  return ranks[rank] + " of " + suits[suit];
}
