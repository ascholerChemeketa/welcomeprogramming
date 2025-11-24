#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {6, 8, 10};
    vector<int> vec2 = {6, 8, 10};
    vector<int> vec3 = {6, 9, 10};
    vector<int> vec4 = {6, 8, 10, 12};

    if (vec < vec2) {
        cout << "vec is less than vec2" << endl;
    } else {
        cout << "vec is NOT less than vec2" << endl;
    }

    if (vec < vec3) {
        cout << "vec is less than vec3" << endl;
    } else {
        cout << "vec is NOT less than vec3" << endl;
    }

    if (vec < vec4) {
        cout << "vec is less than vec4" << endl;
    } else {
        cout << "vec is NOT less than vec4" << endl;
    }
}