Card lastCard() const {
    if (cards.empty())
        return Card{};
    return cards.back();
}