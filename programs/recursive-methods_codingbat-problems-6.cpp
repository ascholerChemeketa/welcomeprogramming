#include <iostream>
#include <vector>
int array11(const vector<int>& nums, int index) {
  if (index >= nums.size()) {
    return 0;
  }
  int recurse = array11(nums, index + 1);
  if (nums[index] == 11) {
    return recurse + 1;
  } else {
    return recurse;
  }
}