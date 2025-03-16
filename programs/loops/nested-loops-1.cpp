#include <iostream>
#include <string>

using namespace std;

int main() {
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            cout << i * j << "\t";
        }
        cout << endl;  //end the row
    }
}