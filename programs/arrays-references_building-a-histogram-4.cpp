vector<int> counts(100, 0);
for (int i = 0; i < counts.size(); ++i) {
  counts[i] = inRange(scores, i, i + 1);
}
