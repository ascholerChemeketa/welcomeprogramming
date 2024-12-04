vector<int> counts(100, 0);
for (int score : scores) {
    if (score >= 0 && score < 100) {
        counts[score]++;
    }
}
