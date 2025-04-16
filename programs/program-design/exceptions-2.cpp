#include <iostream>
#include <string>
#include <exception>

using namespace std;

string mediumJob(const string& s) {
    string mediumResult;
    try {
      // get a string of length 1 starting at index 50
        string substrResult = s.substr(50, 1);
        mediumResult = "mediumJob(" + s + ")";
    } catch (const exception& e) {
        cout << "  Caught exception: " << e.what() << endl;
        mediumResult = "mediumJob(?)";
    }
    return mediumResult;
}

string bigJob(const string& s) {
    string mediumResult = mediumJob(s);
    string bigResult = "bigJob(" + mediumResult + ")";
    return bigResult;
}

int main() {
    string finalResult = bigJob("cat");
    cout << "Result is " << finalResult << endl;
}
