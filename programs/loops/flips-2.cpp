#include <iostream>
#include "SimpleRandom.h"

using namespace std;

int main() {
    int headStreak = 0;
    for (int i = 1; i < 100; ++i) {
        // Print the flip number
        cout << i << ":\t";

        int coinToss = randRange(0, 1);
        if(coinToss == 0) {
            ???;  // Reset the headStreak
            cout << "Tails" << endl;
        } else {
            ???;  // Increment the headStreak
            cout << "Heads. That is " << headStreak 
                 << " in a row." << endl;
        }
    }
}