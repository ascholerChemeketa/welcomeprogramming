int search(const vector<double>& array, double target) {
  for (size_t i = 0; i < array.size(); ++i) {
    if (array[i] == target) {
      return i;
    }
  }
  return -1;
}
