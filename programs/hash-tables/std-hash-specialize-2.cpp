#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// A type that defines ==
struct Person {
    string name;
    int age;
    // built in equality operator that compares both name and age
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Custom hash functor for Person that only uses the name for hashing
struct PersonHash {
    std::hash<string> stringHasher;
    size_t operator()(const Person& p) const {
        return stringHasher(p.name);
    }
};

// Custom equality determiner for Person that only uses the name for equality
struct PersonEqual {
    bool operator()(const Person& p1, const Person& p2) const {
        return p1.name == p2.name;
    }
};


int main() {
    // Create an unordered_map that uses our custom hash and equality functors
    std::unordered_map<Person, string, PersonHash, PersonEqual> personToCity;
    Person alice{"Alice", 30};
    Person bob{"Bob", 25};

    personToCity.emplace(alice, "New York");
    personToCity.emplace(bob, "Los Angeles");

    cout << alice.name << " lives in " << personToCity.at(alice) << endl;
    cout << bob.name << " lives in " << personToCity.at(bob) << endl;
} 