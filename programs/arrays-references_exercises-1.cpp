int banana(const vector<int>& a) {
  int kiwi = 1;
  for (int x : a) {
    kiwi *= x;
  }
  return kiwi;
}
