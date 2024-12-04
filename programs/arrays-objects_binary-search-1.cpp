int binarySearch(const vector<Card>& cards, const Card& target) {
    int low = 0;
    int high = cards.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int comp = cards[mid].compareTo(target);

        if (comp == 0) {
            return mid;
        } else if (comp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
