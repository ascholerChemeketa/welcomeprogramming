// Debugging helper - call this to print out a 2D vector of ints
void print(const vector<vector<int>>& matrix) {
  size_t rows = matrix.size();
  size_t cols = matrix[0].size();
  for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < cols; ++j) {
          cout << matrix.at(i).at(j) << " ";
      }
      cout << endl;
  }
}