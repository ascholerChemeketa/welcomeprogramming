#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<string> words = {"a", "stitch", "in", "time", "saves", "nine"};

    string combined = accumulate(
        words.begin(),
        words.end(),
        string()  // initial value is empty string for concatenation
        // Rely on default operator+ for strings. We could also write:
        //[](const string& a, const string& b) { return a + b; }
    );

    cout << "Combined string: " << combined << endl;
}