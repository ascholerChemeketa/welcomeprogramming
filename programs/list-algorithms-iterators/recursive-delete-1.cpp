#include <iostream>
import SimpleLinkedList;
using namespace std;

int main() {
    SimpleLinkedList myList;
    myList.insertStart(3);
    myList.insertStart(10);
    myList.insertStart(6);
    // List is now 6 -> 10 -> 3

    myList.removeLast();
}