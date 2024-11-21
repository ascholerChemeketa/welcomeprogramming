#include <algorithm>
#include <iostream>
#include <vector>
double maxInRange(const vector<double>& a, int low, int high) {
  if (low == high) {
    return a[low];
  } else {
    double mid = (low + high) / 2;
    double leftMax = maxInRange(a, low, mid);
    double rightMax = maxInRange(a, mid + 1, high);
    return max(leftMax, rightMax);
  }
}
int main() {
  vector<double> a = {1.2, 4.5, 2.7, 9.1, 3.8};
  double max = maxInRange(a, 0, a.size() - 1);
  cout << max << endl; // Output: 9.1
  return 0;
}