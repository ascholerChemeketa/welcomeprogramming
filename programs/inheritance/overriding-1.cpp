#include <format>
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string m_name;
    int m_age;

public:
    Person(string name, int age) {
        m_name = name;
        m_age = age;
    }
    
    string getName() const {
        return m_name;
    }

    void introduce() const {
        cout << "Hi, my name is " << m_name << " and I am " << m_age << " years old." << endl;
    }

    string toString() const {
        return format("Name: {}, Age: {}", m_name, m_age);
    }
};

class Student : public Person {
private:
    string m_major;
public:
    Student(string name, int age, string major)
      : Person(name, age) {
        m_major = major;
    }

    void introduce() const {
        // call the Person version of introduce
        Person::introduce();
        cout << "My major is " << m_major << "." << endl;
    }

    string toString() const {
        string personStr = Person::toString();
        return format("{}, Major: {}", personStr, m_major);
    }
};

int main() {
    Student s("Alex", 20, "Computer Science");
    s.introduce();
}