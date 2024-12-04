int compareTo(const Card& that) const {
    if (this->suit < that.suit)
        return -1;
    if (this->suit > that.suit)
        return 1;
    if (this->rank < that.rank)
        return -1;
    if (this->rank > that.rank)
        return 1;
    return 0;
}
