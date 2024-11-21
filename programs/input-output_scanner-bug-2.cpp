#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
  int age;
  string name;
  cout << "What is your age? ";
  cin >> age;

  // Consume the newline character left by cin
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "What is your name? ";
  getline(cin, name);
  cout << "Hello " << name << ", age " << age << endl;
  return 0;
}