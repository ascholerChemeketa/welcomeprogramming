template<typename T>
struct Node {
    T element;
    Node* next = nullptr;

    Node(T value) { element = value; }
};