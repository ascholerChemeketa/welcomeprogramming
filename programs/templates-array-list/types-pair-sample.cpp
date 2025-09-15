#include <iostream>
using namespace std;

template<typename T>
struct Pair {
    T first;
    T second;
};

int main() {
    // Sample uses:
    Pair<int> intPair;
    intPair.first = 3;
    intPair.second = 4;
    cout << "intPair: " << intPair.first << ", " << intPair.second << endl;

    Pair<double> doublePair = {2.5, 3.7};
    cout << "doublePair: " << doublePair.first << ", " << doublePair.second << endl;
}