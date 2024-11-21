#include <iostream>
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else if (n < 0) {
    return -1; // Error handling for negative input
  } else {
    return 0; // Stub
  }
}