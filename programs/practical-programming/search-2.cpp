#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> words = {"a", "stitch", "in", "time", "saves", "nine"};

    // Count the number of words longer than 3 characters
    int count = count_if(
        words.begin(),
        words.end(),
        // Lambda function to identify words longer than 3 characters
        [](const string& word) { return word.length() > 3; }
    );

    cout << "Number of longer words: " << count << endl;
}