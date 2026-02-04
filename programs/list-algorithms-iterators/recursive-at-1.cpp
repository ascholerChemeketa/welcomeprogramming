#include <iostream>
import SimpleLinkedList;
using namespace std;

int main() {
    SimpleLinkedList myList;
    myList.insertStart(3);
    myList.insertStart(10);
    myList.insertStart(6);
    // List is now 6 -> 10 -> 3

    int first = myList.retrieveAt(0);
    cout << "First element is: " << first << endl;

    int third = myList.retrieveAt(2);
    cout << "Third element is: " << third << endl;
}