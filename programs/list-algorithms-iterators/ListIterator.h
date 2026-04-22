template<typename T>
struct ListNode {
    T element;
    ListNode* next = nullptr;

    ListNode(T value) { element = value; }
};

//-------------------------------------------------------

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

//-------------------------------------------------------

template <typename T>
class LinkedList {
private:
    ListNode<T>* head = nullptr; // Pointer to the first node in the list
    ListNode<T>* tail = nullptr; // Pointer to the last node in the list
public:
    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void insertFront(T value);

    ListIterator<T> begin();
    ListIterator<T> end();
};

template <typename T>
ListIterator<T> LinkedList<T>::begin() {
    return ListIterator<T>(head);
}

template <typename T>
ListIterator<T> LinkedList<T>::end() {
    return ListIterator<T>(nullptr);
}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
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
}