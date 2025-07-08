#include <iostream>
#include <vector>
using namespace std;

int countZeros(vector<int>& numbers) {
  if (numbers.empty()) {
      return 0;
  } else {
      int lastElement = numbers.back();
      numbers.pop_back(); // remove last element
      int count = countZeros(numbers);
      if (lastElement == 0) {
          count = count + 1;
      }
      return count;
  }
}

int main() {
    vector<int> numbers = {0, 1, 2, 0, 3, 0, 4};
    int zeroCount = countZeros(numbers);
    cout << "The number of zeros in the vector is: " << zeroCount << endl;
}