bool isDone() const {
    return one->getHand().isEmpty() || two->getHand().isEmpty();
}