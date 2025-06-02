// Includes and classes hidden...

void makeIntroduction(const Person& person) {
    cout << "Let's meet: " << person.getName() << endl;
    person.introduce();
}

int main() {
    Person p("Wendy", 30);
    Student s("Alex", 20, "Computer Science");

    makeIntroduction(p);
    makeIntroduction(s);
}