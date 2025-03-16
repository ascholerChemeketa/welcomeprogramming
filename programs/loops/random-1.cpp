#include <iostream>
#include "SimpleRandom.h"

using namespace std;

int main() {
    for (int i = 0; i < 10; ++i) {
        int randomNumber = randRange(1, 6);
        cout << randomNumber << endl;
    }
}