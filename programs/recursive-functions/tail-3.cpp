#include <iostream>
using namespace std;

int factorial(int n, int accumulator) {
  if (n == 0) {
      return accumulator;
  } else {
      int newAccumulator = accumulator * n;
      return factorial(n - 1, newAccumulator);
  }
}

//non-recursive kick starter
int factorial(int n) {
    // Start with accumulator as 1 as 1 * anything is that anything
    return factorial(n, 1); 
}

int main() {
    int n = 4; 
    int result = factorial(n);
    cout << "Factorial of " << n << " is: " << result << endl;
}