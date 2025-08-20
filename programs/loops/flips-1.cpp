#include <iostream>
import SimpleRandom;

using namespace std;

int main() {
    for (int i = 1; i <= 10; ++i) {
        // Print the flip number
        cout << i << ":\t";

        int coinToss = randRange(0, 1);
        if(coinToss == 0) {
            cout << "Tails" << endl;
        } else {
            cout << "Heads" << endl;
        }
    }
}