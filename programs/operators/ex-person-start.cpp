#include <iostream>
#include <algorithm>

using namespace std;


class Person {
public:
    Person(string first, string last) {
        m_firstName = first;
        m_lastName = last;
    }

    bool operator<(const Person& other) const;

    string toString() const {
        return m_lastName + ", " + m_firstName;
    }

private:
    string m_firstName;
    string m_lastName;
};