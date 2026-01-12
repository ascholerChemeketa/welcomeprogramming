#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;

};

int main() {
    // Create a set of Person structs
    vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    sort(
        people.begin(), 
        people.end(),