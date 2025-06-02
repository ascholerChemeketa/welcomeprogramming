// Includes and classes hidden...

int main() {
    Person p("Wendy", 30);
    Student s("Alex", 20, "Computer Science");

    Student& studentRef1 = p;
    Student& studentRef2 = s;

    studentRef1.introduce();
    studentRef2.introduce();
}