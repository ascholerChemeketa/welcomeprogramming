#include <iostream>
#include <vector>

int search(const vector<double>& array, double target) {
  for (size_t i = 0; i < array.size(); ++i) {
    if (array[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  vector<double> array = {3.14, -55.0, 1.23, -0.8};
  int index = search(array, 1.23);
  cout << index << endl;
  return 0;
}
