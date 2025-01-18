int index = 0;
for (int suit = 0; suit <= 3; ++suit) {
    for (int rank = 1; rank <= 13; ++rank) {
        cards[index] = Card(rank, suit);
        ++index;
    }
}
