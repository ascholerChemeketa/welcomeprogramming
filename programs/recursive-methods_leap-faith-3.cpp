#include <iostream>

using namespace std;

int fibonacci(int n) {
  if (n <= 0) {
    return 0; // Error handling for invalid input
  } else if (n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}