// simple example of set of Person struct
#include <iostream>
#include <set>
using namespace std;

struct Person {
    string name;
    int age;

    bool operator<(const Person& other) const {
        return name < other.name; // Order by name
    }
};

struct PersonAgeComparer {
    bool operator()(const Person& a, const Person& b) const {
        return a.age > b.age; // Compare by age descending
    }
};

int main() {
    // Create a set of Person structs
    set<Person, PersonAgeComparer> people = {
        {"Bob", 25}, {"Alice", 30}, {"Charlie", 35}};

    for (const auto& person : people) {
        cout << "Name: " << person.name << ", Age: " << person.age << endl;
    }
}