int pineapple(const vector<int>& a, int apple) {
  int pear = 0;
  for (int pine : a) {
    if (pine == apple) {
      pear++;
    }
  }
  return pear;
}
