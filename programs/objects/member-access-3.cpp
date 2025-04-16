#include <iostream>
#include <string>
using namespace std;


class Person {
public:
    // Construct a Person
    Person(string n, int a) {
        m_name = n;
        m_age = a;
    }

    double getAge() {
        return m_age;
    }

    void setAge(int newAge) {
        if(newAge > 0) {
            m_age = newAge;
        } else {
            cout << "Invalid age. Not changing." << endl;
        }
    }
private:
    string m_name;
    int m_age;
};

int main() {
    Person p1("Alice", 30);
    cout << "Age: " << p1.getAge() << endl;

    p1.setAge(35);
    cout << "New Age: " << p1.getAge() << endl;

    p1.setAge(-5); // Invalid age
    cout << "After invalid age attempt: " << p1.getAge() << endl;
}