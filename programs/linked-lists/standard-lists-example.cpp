#include <forward_list>
#include <iostream>
#include <list>
using namespace std;

int main() {
    // create a standard linked list of integers
    list<int> myList;

    // add some values to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // print the list using an iterator based loop
    cout << "List contents: ";
    for (int value : myList) {
        cout << value << " ";
    }
    cout << endl;

    // remove the first value
    myList.pop_front();

    // print using an iterator
    cout << "After pop_front: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}