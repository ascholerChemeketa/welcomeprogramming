if (!cin >> x) {
    string word;
    cin >> word;
    cerr << word << " is not a number\n";
    return 1; // Indicate an error
}