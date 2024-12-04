int grapefruit(const vector<int>& a, int grape) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == grape) {
            return i;
        }
    }
    return -1;
}
