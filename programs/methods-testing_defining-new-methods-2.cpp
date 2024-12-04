#include <iostream>

void newLine() {
    cout << endl;
}

void threeLine() {
    newLine();
    newLine();
    newLine();
}

int main() {
    cout << "First line.\n";
    threeLine();
    cout << "Second line.\n";
    return 0;
}