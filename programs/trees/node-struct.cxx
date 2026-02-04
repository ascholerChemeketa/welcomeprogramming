struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value) {
        data = value;
    }
};