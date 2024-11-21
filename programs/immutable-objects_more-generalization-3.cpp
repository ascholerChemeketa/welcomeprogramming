void printRow(int n, int cols) {
  for (int i = 1; i <= cols; ++i) {
    printf("%4d", n * i);
  }
  printf("\n");
}