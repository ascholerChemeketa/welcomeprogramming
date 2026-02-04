struct ListNode {
    // Value stored in this node
    int data = 0;

    // Next node in list (nullptr == end of list)
    ListNode* next = nullptr;

    // Constructor
    ListNode(int value) {
        data = value;
    }
};