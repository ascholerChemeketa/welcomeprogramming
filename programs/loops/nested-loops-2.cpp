#include <iostream>
#include <string>

using namespace std;

int main() {
    for (int row = 1; row <= 4; ++row) {
        for (int col = 1; col <= 4; ++col) {
            cout << row * col << "\t";
        }
        cout << endl;  //end the row
    }
}