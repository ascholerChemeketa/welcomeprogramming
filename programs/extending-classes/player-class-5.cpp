bool cardMatches(const Card& card1, const Card& card2) {
    return card1.suit == card2.suit || card1.rank == card2.rank
           || card1.rank == 8;
}