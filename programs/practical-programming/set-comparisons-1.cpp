#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    // Create a set of Person structs
    set<Person> people = {{"Bob", 25}, {"Alice", 30}, {"Charlie", 35}};
}