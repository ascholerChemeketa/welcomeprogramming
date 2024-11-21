#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
  for (int i = 0; i < argc; ++i) {
    cout << argv[i] << " ";
  }
  cout << endl;
  return 0;
}