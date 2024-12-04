Card popCard() {
    if (cards.empty())
        return Card(); // Return a default constructed Card if the vector is
                       // empty
    Card c = cards.back();
    cards.pop_back();
    return c;
}