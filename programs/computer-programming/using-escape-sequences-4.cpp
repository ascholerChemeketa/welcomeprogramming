#include <iostream>
#include <string>

using namespace std;

int main() {
  // We do not have to escape the \ in a raw string
  string rawText = R"(c:\Programs\some\folder\program.exe)";
  cout << rawText << endl;
  
  cout << "----------------------" << endl;
  
  // A raw string can have span multiple lines
  string rawText2 = R"(A programmer, quite stressed, it appears,
Found a bug bringing endless new fears.
With a sigh and a frown,
He tracked the thing down,
Then fixed it and shed happy tears.)";
  
  cout << rawText2 << endl;
}
