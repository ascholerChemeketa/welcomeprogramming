module;
export module ListNode;

template<typename T>
export struct Node {
    T element;
    Node* next = nullptr;

    Node(T value) { element = value; }
};
