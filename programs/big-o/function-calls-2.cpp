#include <iostream>
using namespace std;

void printRow(int size) {
    for (int i = 0; i < size; i++) {
        cout << "*";
    }
    cout << endl;
}

void printGrid(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int size;
    cin >> size;
    printRow(size);
    printGrid(size);
    printRow(size * 2);
}