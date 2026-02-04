template<typename T>
struct ListNode {
    T element;
    ListNode* next = nullptr;

    ListNode(T value) { element = value; }
};

template <typename T>
class ListIterator {
private:
    ListNode<T>* currentNode;
public:
    // Constructor to initialize the iterator that starts at a given node
    ListIterator(ListNode<T>* startNode) {
        currentNode = startNode;
    }

    // Returns a reference to the element at the current position
    T& operator*() {
        return currentNode->element;
    }

    // Advances the iterator to the next position
    ListIterator& operator++() {
        currentNode = currentNode->next;
        return *this;
    }

    // Compare two iterators for equality/inequality
    bool operator==(const ListIterator& other) const {
        return currentNode == other.currentNode;
    }

    bool operator!=(const ListIterator& other) const {
        return currentNode != other.currentNode;
    }
};

template <typename T>
class SinglyLinkedList {
private:
    ListNode<T>* head = nullptr; // Pointer to the first node in the list
    ListNode<T>* tail = nullptr; // Pointer to the last node in the list
    size_t size = 0;             // Number of elements in the list
public:
    // Construct an empty linked list
    SinglyLinkedList();

    // Destructor to clean up the list
    ~SinglyLinkedList();

    // Add a new element to the front of the list
    void insertFront(T value);
    
    // Remove the first element from the list
    void removeFirst();

    // Add a new element to the end of the list
    void insertBack(T value);

    // Get the number of elements in the list
    size_t getSize() const;

    ListIterator<T> begin();
    ListIterator<T> end();
};

template <typename T>
ListIterator<T> SinglyLinkedList<T>::begin() {
    return ListIterator<T>(head);
}

template <typename T>
ListIterator<T> SinglyLinkedList<T>::end() {
    return ListIterator<T>(nullptr);
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (head != nullptr) {
        removeFirst();
    }
}

template <typename T>
void SinglyLinkedList<T>::insertFront(T value) {
    ListNode<T>* newNode = new ListNode<T>(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    size++;
}

template <typename T>
void SinglyLinkedList<T>::removeFirst() {
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
void SinglyLinkedList<T>::insertBack(T value) {
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

template <typename T>
size_t SinglyLinkedList<T>::getSize() const {
    return size;
}
