// total up all the values in numbers
int total(const vector<int>& numbers) {
    int total = 0;
    for (int x : numbers) {
        total += x;
    }
    return total;
}