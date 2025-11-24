#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {6, 8, 10};
    vector<int> vec2 = {6, 8, 10};
    vector<int> vec3 = {6, 7, 10};
    vector<int> vec4 = {6, 8, 10, 12};

    if (vec == vec2) {
        cout << "vec and vec2 are equal" << endl;
    } else {
        cout << "vec and vec2 are NOT equal" << endl;
    }

    if (vec == vec3) {
        cout << "vec and vec3 are equal" << endl;
    } else {
        cout << "vec and vec3 are NOT equal" << endl;
    }

    if (vec == vec4) {
        cout << "vec and vec4 are equal" << endl;
    } else {
        cout << "vec and vec4 are NOT equal" << endl;
    }
}