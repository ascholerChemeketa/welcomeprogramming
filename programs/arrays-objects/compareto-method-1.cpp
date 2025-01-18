bool equals(const Card& that) const {
    return this->rank == that.rank && this->suit == that.suit;
}
