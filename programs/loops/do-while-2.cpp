#include <iostream>
#include "SimpleRandom.h"

using namespace std;

int main() {
    int tries = 0;
    int die1 = 0;
    int die2 = 1;  // So the loop runs at least once
    while(die1 != die2) {
        ++tries;
        die1 = randRange(1, 6);
        die2 = randRange(1, 6);
        cout << "You rolled " << die1 << " and " << die2 << endl;
    } 
    cout << "It took " << tries << " tries to roll doubles." << endl;
}