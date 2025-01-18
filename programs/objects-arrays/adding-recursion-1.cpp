/* This function implements the merge sort algorithm for a Deck of cards.  Note
 * that this is a skeletal implementation; you'll need to define the Deck class
 * and its methods (e.g., splitting the deck, comparing cards, merging sorted
 * subdecks). */
#include <iostream>

// Define your Deck class here.  It needs to support:
//  - A way to access individual cards (e.g., operator[])
//  - A way to split the deck in half
//  - A way to merge two sorted decks
//  - A way to compare two cards (less than, greater than etc.)
class Deck {
  public:
    // ... Your Deck class methods ...
    Deck mergeSort() {
        // Base case: deck with 0 or 1 cards is already sorted
        if (size() <= 1) {
            return *this;
        }

        // Split the deck into two halves
        Deck left, right;
        split(left, right);

        // Recursively sort the subdecks
        left = left.mergeSort();
        right = right.mergeSort();

        // Merge the sorted subdecks
        return merge(left, right);
    }

  private:
    // ... Your Deck class data members and private methods ...
    int size(){/*Returns the number of cards in the deck*/};
    void split(Deck& left, Deck& right){/* Splits the deck into two halves*/};
    Deck merge(Deck& left, Deck& right){/* Merges two sorted decks*/};
};

int main() {
    // Example Usage
    return 0;
}