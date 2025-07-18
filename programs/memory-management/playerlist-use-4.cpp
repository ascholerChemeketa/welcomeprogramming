#include <iostream>
using namespace std;

import PlayerList;

int main() {
    cout << "Start of main" << endl;

    PlayerList pList(3); // Create a PlayerList with space for 3 players
    pList.setPlayerName(0, "Alice");
    pList.setPlayerName(1, "Bob");
    pList.setPlayerName(2, "Carlos");
    pList.print();

    PlayerList other(1); // Create a PlayerList with space for 1 player
    other.setPlayerName(0, "Diana");
    other.print();

    other = pList;
    cout << "After assignment, other PlayerList:" << endl;
    other.print();

    cout << "End of main" << endl;
}