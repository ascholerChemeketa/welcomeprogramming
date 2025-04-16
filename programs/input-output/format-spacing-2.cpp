#include <iostream>
#include <string>
#include <format>
using namespace std;

int main() {
    int a = 123;
    int b = 789;
    // Fill with -'s and align to the left
    cout << format("{:-<10}", a) << endl;
    // Fill with -'s and align to the center
    cout << format("{:-^10}", a) << endl;
    // No fill, just left align
    cout << format("{:<10}", a) << endl;
    // No fill, just center
    cout << format("{:^10}", a) << endl;
}