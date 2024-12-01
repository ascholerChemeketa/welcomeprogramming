#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << 1 + 2 << "Hello" << endl;  // Output: 3Hello
  cout << "Hello" << 1 + 2 << endl;  // Output: Hello3
  cout << "Hello" << 1 << 2 << endl; // Output: Hello12
  return 0;
}