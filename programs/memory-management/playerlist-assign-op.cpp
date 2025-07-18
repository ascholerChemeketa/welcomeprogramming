export class PlayerList {
private:
    string* m_players; // pointer to the array of player names
    int m_size; // number of players in the list
public:
  ...
  PlayerList& operator=(const PlayerList& other);  // Assignment operator
  ...
};

PlayerList& PlayerList::operator=(const PlayerList& other) {
    // Check for self-assignment
    if (this != &other) { 
        // Deallocate existing memory
        delete[] m_players;

        // Copy non-pointer members
        m_size = other.m_size;

        // Allocate own dynamic storage
        m_players = new string[m_size];

        // Copy the contents from the other PlayerList
        for (int i = 0; i < m_size; ++i) {
            m_players[i] = other.m_players[i];
        }
    }
    return *this;  // Return the current object
}
...