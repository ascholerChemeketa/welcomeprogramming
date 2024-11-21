#include <iostream>
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else if (n < 0) {
    return -1; // Error handling for negative input
  } else {
    return n * factorial(n - 1);
  }
}