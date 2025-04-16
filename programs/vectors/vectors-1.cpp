// outer loop: for each lowercase letter
for (char c = 'a'; c <= 'z'; ++c) {
    // inner loop: count how many times the letter appears
    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (tolower(str.at(i)) == c) {
            ++count;
        }
    }
    // print the letter and its count
    cout << c << ": " << count << endl;
}