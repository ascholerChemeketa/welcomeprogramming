int inRange(const vector<int>& a, int low, int high) {
    int count = 0;
    for (int x : a) {
        if (x >= low && x < high) {
            count++;
        }
    }
    return count;
}
