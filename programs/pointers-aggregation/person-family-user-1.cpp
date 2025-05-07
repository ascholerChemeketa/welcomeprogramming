#include <iostream>

import Person;

using namespace std;

int main() {
    Person anna("Anna");
    Person bob("Bob");
    Person carl("Carl");
    Person diana("Diana");
    Person erin("Erin");
    Person fay("Fay");
    Person george("George");
    Person henry("Henry");

    // Set up family relationships
    bob.setMother(&anna);
    carl.setMother(&anna);
    diana.setMother(&anna);
    erin.setMother(&diana);
    fay.setMother(&diana);
    george.setMother(&fay);
    henry.setMother(&fay);

    // Print some Person objects
    anna.print();
    fay.print();
    henry.print();

    fay.setName("Fiona");
    cout << "After changing Fay's name to Fiona:" << endl;
    henry.print();
}