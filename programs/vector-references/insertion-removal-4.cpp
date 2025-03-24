#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> letters = {'c', 'e'};
    letters.insert(letters.begin(), 'a'); // insert 'a' at the beginning
    // now letters is {'a', 'c', 'e'}
    letters.insert(letters.begin() + 1, 'b'); // insert 'b' at index 1
    // now letters is {'a', 'b', 'c', 'e'}
    letters.insert(letters.begin() + 3, 'd'); // insert 'd' at index 3
    // now letters is {'a', 'b', 'c', 'd', 'e'}
    letters.insert(letters.end(), 'f'); // insert 'f' at the end

    // print all the letters - covered in the next section
    for (char c : letters) {
        cout << c << " ";
    }
}