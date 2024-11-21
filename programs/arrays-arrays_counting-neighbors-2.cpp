int countAlive(int r, int c) {
  int count = 0;
  count += grid.test(r - 1, c - 1);
  count += grid.test(r - 1, c);
  count += grid.test(r - 1, c + 1);
  count += grid.test(r, c - 1);
  count += grid.test(r, c + 1);
  count += grid.test(r + 1, c - 1);
  count += grid.test(r + 1, c);
  count += grid.test(r + 1, c + 1);
  return count;
}