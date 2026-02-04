import ListNode;

template<typename T>
class SimpleLinkedList {
private:
    ListNode<T>* head = nullptr; // Pointer to the first node in the list
public:
    // Construct an empty linked list
    SimpleLinkedList();

    // Destructor to clean up the list
    ~SimpleLinkedList();

    // Add a new element to the front of the list
    void insertFront(T value);

    // Print all elements in the list
    void print() const;
};
