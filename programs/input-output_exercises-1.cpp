#include <iostream>
#include <random>

int main() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(1, 100);
  cout << distrib(gen) << endl;
  return 0;
}