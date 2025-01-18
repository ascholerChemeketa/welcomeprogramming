string reverse(const string& s) {
    string r = "";
    for (int i = s.length() - 1; i >= 0; --i) {
        r += s[i];
    }
    return r;
}