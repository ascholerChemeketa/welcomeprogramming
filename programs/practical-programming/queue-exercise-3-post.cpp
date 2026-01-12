

    char c;
    cin >> c;
    if (!charMap.contains(c)) {
        cout << "Unknown character!";
    } else {
        string result = charMap.at(c);
        cout << result;
    }
}