public Player nextPlayer(Player current) {
    if (current == one) {
        return two;
    } else {
        return one;
    }
}