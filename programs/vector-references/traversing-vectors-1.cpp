#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < a.size(); ++i) {
        cout << "a.at(" << i << "): " << a.at(i);
    }
}


