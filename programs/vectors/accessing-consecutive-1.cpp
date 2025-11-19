#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {12, 14, 21, 22, 28};

    // Assume items are in order, look for a problem
    bool inOrder = true;
    for (size_t i = 1; i < vec.size(); ++i) {
        // check if current item is less than previous
        if (vec.at(i) < vec.at(i - 1)) {
            // Found a problem
            inOrder = false;
            // No point in continuing the loop
            break;
        }
    }
    if (inOrder) {
        cout << "The vector is in order" << endl;
    } else {
        cout << "The vector is not in order" << endl;
    }
}


