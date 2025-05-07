#include <iostream>

import Person;

using namespace std;

int main() {
    Person p1("Anna");
    Person p2("Bob");
    Person p3("Carl");
    Person p4("Diana");
    Person p5("Erin");
    Person p6("Fay");
    Person p7("George");
    Person p8("Henry");

    // Set up family relationships
    p2.setMother(&p1);
    p3.setMother(&p1);
    p4.setMother(&p1);
    p5.setMother(&p4);
    p6.setMother(&p5);
    p7.setMother(&p6);
    p8.setMother(&p6);

    // Print some Person objects
    Person* currentPerson = &henry;

    while (currentPerson != nullptr) {
        //Print the current person's information
        cout << "-------------------------" << endl;
        cout << "Current Person address is " << currentPerson << endl;
        cout << "They are: ";
        currentPerson->print();
        // Get the mother of the current person
        Person* currentMother = currentPerson->getMother();
        cout << "Their mother's address is " << currentMother << endl;
        // Change the current person pointer to point to the mother
        currentPerson = currentMother;
    }
    cout << "Reached the top of the family tree." << endl;
}