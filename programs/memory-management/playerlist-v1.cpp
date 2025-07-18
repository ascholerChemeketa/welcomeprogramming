module;

#include <iostream>
#include <string>

export module PlayerList;

using namespace std;

export class PlayerList {
private:
    string* m_players; // pointer to the array of player names
    int m_size; // number of players in the list
public:
  PlayerList(int size);

  void setPlayerName(int index, const string& name);

  void print() const;
};

PlayerList::PlayerList(int size) {
    if (size <= 0) {
        throw invalid_argument("Size must be positive");
    }
    m_size = size;
    m_players = new string[m_size]; // allocate memory for the array
}

void PlayerList::setPlayerName(int index, const string& name) {
    if (index < 0 || index >= m_size) {
        throw out_of_range("Index out of range");
    }
    m_players[index] = name; // set the player name at the given index
}

void PlayerList::print() const {
    cout << "Player List: ";
    for (int i = 0; i < m_size; ++i) {
        cout << m_players[i] << " ";
    }
    cout << endl;
}