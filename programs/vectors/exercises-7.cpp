#include <iostream>
#include <vector>

vector<int> make(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a.at(i) = i + 1;
    }
    return a;
}

void dub(vector<int>& jub) {
    for (int& x : jub) {
        x *= 2;
    }
}

int mus(const vector<int>& zoo) {
    int fus = 0;
    for (int x : zoo) {
        fus += x;
    }
    return fus;
}

void printArray(const vector<int>& a) {
    cout << "{";
    if (!a.empty()) {
        cout << a.at(0);
        for (size_t i = 1; i < a.size(); ++i) {
            cout << ", " << a.at(i);
        }
    }
    cout << "}" << endl;
}

int main() {
    vector<int> bob = make(5);
    dub(bob);
    cout << mus(bob) << endl;
    return 0;
}
