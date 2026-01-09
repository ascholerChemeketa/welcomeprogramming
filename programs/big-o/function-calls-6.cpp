#include <iostream>
using namespace std;

void printRow(int size) {
    // O(n) work where n = size
}

void printGrid(int size) {
    // O(n^2) work where n = size
}

int main() {
    int size;
    cin >> size;
    // O(n) work for printRow(size)
    // O(n^2) work for printGrid(size)
    printRow(size * 2);
}