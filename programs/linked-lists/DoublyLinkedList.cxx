module;

#include <cassert>
#include <iostream>
#include <stdexcept>

export module DoublyLinkedList;

using namespace std;

///-----------------------------LIST NODE---------------------------------
export template<typename T>
struct ListNode {
  T data;
  ListNode<T>* next;
  ListNode<T>* prev;

  // Maintain a count of active nodes for testing
  //  Not normally a part of the struct.
  //  You should NOT modify or even use this value in your code.
  static int nodeCount;

  ListNode() {
    next = nullptr;
    prev = nullptr;
    // Call default constructor for type T
    //   produces 0 for primitive types
    data = T();
    nodeCount++;
  }

  ListNode(const T& value) {
    next = nullptr;
    prev = nullptr;
    data = value;
    nodeCount++;
  }

  ~ListNode() {
    nodeCount--;
  }
};

template<typename T>
int ListNode<T>::nodeCount = 0;

///-----------------------------LINKED LIST---------------------------------
export template<typename T>
class DoublyLinkedList {
  // These would normally be private.
  // They are public to enable simpler unit tests.
public:
  ListNode<T>* head;
  ListNode<T>* tail;
  int size;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  // Assignment Operator and Copy Ctor not implemented
  // declare as = delete to prevent default shallow versions
  DoublyLinkedList(const DoublyLinkedList& other) = delete;
  DoublyLinkedList& operator=(const DoublyLinkedList& other) = delete;

  int listSize() const;

  void insertStart(const T& value);
  void removeEnd();

  void insertAt(int index, const T& value);
  void removeAt(int index);
  T retrieveAt(int index) const;

  void print() const;
};

///-----------------------------LINKED LIST FUNCTIONS-----------------------
template<typename T>
void DoublyLinkedList<T>::print() const {
  ListNode<T>* current = head->next;
  while (current != tail) {
    cout << current->data;
    if (current->next != tail)
      cout << ", ";
    current = current->next;
  }
  cout << endl;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  // Delete all nodes, including dummies
  while (head != nullptr) {
    ListNode<T>* temp = head;
    head = head->next;
    delete temp;
  }
}

template<typename T>
int DoublyLinkedList<T>::listSize() const {
  return size;
}

template<typename T>
void DoublyLinkedList<T>::insertStart(const T& value) {
  ListNode<T>* newNode = new ListNode<T>(value);
  newNode->prev = head;
  newNode->next = head->next;

  newNode->next->prev = newNode;
  head->next = newNode;

  size++;
}

template<typename T>
T DoublyLinkedList<T>::retrieveAt(int index) const {
  if (index >= size || index < 0)
    throw out_of_range("Bad index in retrieveAt");

  // Start at node after dummy
  ListNode<T>* current = head->next;
  // Advance index times
  for (int i = 0; i < index; i++)
    current = current->next;

  return current->data;
}
