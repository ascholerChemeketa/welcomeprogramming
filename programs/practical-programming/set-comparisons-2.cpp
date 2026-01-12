#include <iostream>
#include <set>
using namespace std;

struct Person {
    string name;
    int age;

    // Define less-than operator for ordering in set
    bool operator<(const Person& other) const {
        return name < other.name; // Order by name
    }
};

int main() {
    // Create a set of Person structs
    set<Person> people = {{"Bob", 25}, {"Alice", 30}, {"Charlie", 35}};

    for (const auto& person : people) {
        cout << "Name: " << person.name << ", Age: " << person.age << endl;
    }
}