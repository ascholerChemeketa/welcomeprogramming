#include <iostream>
#include <vector>
using namespace std;

double minValue(const vector<double>& values) {
    // assume the first element is the minimum
    double minimum = values.at(0);
    // loop through the rest of the vector to see if any elements are smaller
    for (size_t i = 1; i < values.size(); ++i) {
        double value = values.at(i);
        if (value < minimum) {
            minimum = value; // found a new minimum
        }
    }
    return minimum;
}

int main() {
    vector<double> data = {4.5, 2.3, 5.7, 1.9, 3.6};
    double minVal = minValue(data);
    cout << "Minimum value is: " << minVal << endl;
}