#include <algorithm>
#include <iostream>
#include <numeric>

#include "ListIterator.h"

using namespace std;

bool isOdd(int x) {
    return x % 2 == 1;
}

int main() {
    SinglyLinkedList<int> myList;
    myList.insertBack(10);
    myList.insertBack(20);
    myList.insertBack(15);
    myList.insertBack(6);

    // A range based loop will implicitly use our iterator
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;

    // Use std::accumulate to add all the values
    cout << "Sum is: " << std::accumulate(myList.begin(), myList.end(), 0)
         << endl;

    // Use std::replace_if to modify the list
    cout << "Replacing all odd values with 0" << endl;
    std::replace_if(myList.begin(), myList.end(), isOdd, 0);
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;
}
