#include <iostream>
#include <random>
#include <vector>

vector<int> randomArray(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 99);
    vector<int> a(size);
    for (int i = 0; i < size; ++i) {
        a[i] = distrib(gen);
    }
    return a;
}

void printArray(const vector<int>& a) {
    cout << "{";
    if (!a.empty()) {
        cout << a[0];
        for (size_t i = 1; i < a.size(); ++i) {
            cout << ", " << a[i];
        }
    }
    cout << "}" << endl;
}

int main() {
    vector<int> array = randomArray(8);
    printArray(array);
    return 0;
}
