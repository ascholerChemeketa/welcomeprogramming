int countZeros(const vector<int>& numbers) {
  if (numbers.empty()) {
      return 0;
  } else {
      int lastElement = numbers.back();
      vector<int> copy = numbers; // create a copy
      copy.pop_back(); // remove last element from the copy
      int count = countZeros(numbers);
      if (lastElement == 0) {
          count = count + 1;
      }
      return count;
  }
}