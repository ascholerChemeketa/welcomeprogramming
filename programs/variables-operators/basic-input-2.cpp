#include <iostream>
using namespace std;

int main() {
    // Prompt the user
    cout << "Enter four numbers: " << endl;

    // Get the first two
    int num1, num2, num3, num4;
    cin >> num1 >> num2;
    // get two more
    cin >> num3 >> num4;

    cout << "The numbers are: " 
         << num1 << ", " << num2 << ", " << num3 << ", " << num4 << endl;

    // Calculate the sum
    int sum = num1 + num2 + num3 + num4;
    cout << "The sum is: " << sum << endl;
}