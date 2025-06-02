module;

#include <iostream>
#include <string>
#include <vector>

export module Person;

using namespace std;

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
    Person* getChild(size_t childNum) const;

    void print() const;
};

Person::Person(const string& name) : m_name(name) {
    // m_name = name;
    m_mother = nullptr;
    // vector starts empty by default
}

void Person::setName(const string& name) {
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

Person* Person::getChild(size_t childNum) const {
    // The vector will throw an exception if the index is out of bounds
    return m_children.at(childNum);
}

void Person::print() const {
    cout << "Person: " << m_name;
    if (m_mother) {
        cout << " Mother is: " << m_mother->m_name;
    }
    if (hasChildren()) {
        cout << ", Children: ";
        for (Person* child : m_children) {
            cout << child->m_name << " ";
        }
    }
    cout << endl;
}