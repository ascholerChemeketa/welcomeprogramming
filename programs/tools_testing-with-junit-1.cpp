#include <iostream>
int fibonacci(int n) {
  if (n <= 0) {
    return 0; // Error handling for invalid input
  } else if (n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
int main() {
  if (fibonacci(1) != 1) {
    cerr << "fibonacci(1) is incorrect\n";
  }
  if (fibonacci(2) != 1) {
    cerr << "fibonacci(2) is incorrect\n";
  }
  if (fibonacci(3) != 2) {
    cerr << "fibonacci(3) is incorrect\n";
  }
  return 0;
}