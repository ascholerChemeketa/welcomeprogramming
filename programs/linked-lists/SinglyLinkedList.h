#include "ListNode.h"

template <typename T>
class LinkedList {
private:
    ListNode<T>* head = nullptr; // Pointer to the first node in the list
    ListNode<T>* tail = nullptr; // Pointer to the last node in the list
    size_t size = 0;             // Number of elements in the list
public:
    // Construct an empty linked list
    LinkedList();

    // Destructor to clean up the list
    ~LinkedList();

    // Add a new element to the front of the list
    void insertFront(T value);
    
    // Remove the first element from the list
    void removeFirst();

    // Add a new element to the end of the list
    void insertBack(T value);

    // Get the number of elements in the list
    size_t getSize() const;

    // Disable copying and assignment to prevent accidental shallow copies of the list
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        removeFirst();
    }
}

template <typename T>
void LinkedList<T>::insertFront(T value) {
    ListNode<T>* newNode = new ListNode<T>(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::removeFirst() {
    if (head != nullptr) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

template <typename T>
void LinkedList<T>::insertBack(T value) {
    ListNode<T>* newNode = new ListNode<T>(value);
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    size++;
}