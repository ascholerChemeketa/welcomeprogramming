#include <iostream>
#include "SimpleRandom.h"

using namespace std;

int main() {
    int tries = 0;
    int die1, die2;
    do {
        die1 = randRange(1, 6);
        die2 = randRange(1, 6);
        ++tries;
        cout << "You rolled " << die1 << " and " << die2 << endl;
    } while(die1 != die2);
    cout << "It took " << tries << " tries to roll doubles." << endl;
}