module;

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

export module Person;

export class Person {
private:
    string m_name;
    Person* m_mother;
    vector<Person*> m_children;

public:
    Person(const string& name);
    void setName(const string& name);

    Person* getMother() const;
    void setMother(Person* mother);

    bool hasChildren() const;
    Person* getChild(int childNum) const;

    void print() const;
};

Person::Person(const string& name) {
    m_name = name;
    m_mother = nullptr;
    // vector starts empty by default
}

void setName(const string& name) {
    m_name = name;
}

Person* Person::getMother() const {
  return m_mother;
}

void Person::setMother(Person* mother) {
  m_mother = mother;
  mother->m_children.push_back(this);
}

bool Person::hasChildren() const {
  return m_children.size() > 0;
}

Person* Person::getChild(int childNum) const {
  if (childNum < 0 || childNum >= m_children.size()) {
      throw logic_error("Invalid child number.");
  }
  return m_children.at(childNum);
}

void Person::print() const {
  cout << "Person: " << m_name;
  if (m_mother) {
      cout << ", Mother: " << m_mother->m_name;
  }
  if (hasChildren()) {
      cout << ", Children: ";
      for (Person* child : m_children) {
          cout << child->m_name << " ";
      }
  }
  cout << endl;
}