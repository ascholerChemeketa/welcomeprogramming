#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// A type that defines ==
struct Person {
    string name;
    int age;
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Add a specialization of std::hash for our Person type
// Adding to the std namespace
namespace std {

  // There is no "type T" as we are fully specializing the template
  template<>
  struct hash<Person> {
      // store hashers as member variables to avoid constructing them every time
      std::hash<string> stringHasher;
      std::hash<int> intHasher;
      size_t operator()(const Person& p) const {
          size_t h1 = stringHasher(p.name);
          size_t h2 = intHasher(p.age);

          return h1 ^ (h2 << 1);
      }
  };

} // namespace std

int main() {
    std::unordered_map<Person, string> personToCity;

    Person alice{"Alice", 30};
    Person bob{"Bob", 25};

    personToCity.emplace(alice, "New York");
    personToCity.emplace(bob, "Los Angeles");

    cout << alice.name << " lives in " << personToCity.at(alice) << endl;
    cout << bob.name << " lives in " << personToCity.at(bob) << endl;
} 