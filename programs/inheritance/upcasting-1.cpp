// Includes and classes hidden...

int main() {
    Person p("Wendy", 30);
    Student s("Alex", 20, "Computer Science");

    Person& personRef1 = p;
    Person& personRef2 = s;

    personRef1.introduce();
    personRef2.introduce();
}