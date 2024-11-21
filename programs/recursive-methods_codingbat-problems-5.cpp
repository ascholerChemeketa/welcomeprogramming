#include <iostream>
#include <vector>

int func(const vector<int>& nums, int index) {
  if (index >= nums.size()) {
    return 0;
  }
  // Add your code here to process the element at nums[index]
  return nums[index]; // Replace with your actual logic
}