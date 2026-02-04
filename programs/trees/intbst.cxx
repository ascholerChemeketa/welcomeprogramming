module;

#include <iostream>

export module IntBST;

export struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value) {
        data = value;
    }
};

export class IntBST {
private:
    Node* root = nullptr;

public:
    IntBST();
    ~IntBST();                              // Destructor
    IntBST(const IntBST& other);            // Copy constructor
    IntBST& operator=(const IntBST& other); // Assignment operator

    bool find(int target);
    void insert(int value);
    void remove(int value);
    void clear();
    int size();

    void printInOrder();
};

IntBST::IntBST() {
    // root is already initialized to nullptr
}

bool findRecursive(Node* node, int target) {
    if (node == nullptr) {
        return false; // Base case: target not found
    }
    if (node->data == target) {
        return true; // Base case: target found
    } else if (target < node->data) {
        return findRecursive(node->left, target); // Search left subtree
    } else {
        return findRecursive(node->right, target); // Search right subtree
    }
}

bool IntBST::find(int target) {
    // Start the recursive search at the root
    return findRecursive(root, target);
}

Node* insertRecursive(Node* node, int value) {
    if (node == nullptr) {
        // found location
        Node* newNode = new Node(value);
        return newNode; // return the new node
    } else if (value < node->data) {
        // belongs in left subtree, hand it off
        // set left child to result of insertion
        node->left = insertRecursive(node->left, value);
    } else {
        // belongs in right subtree, hand it off
        // set right child to result of insertion
        node->right = insertRecursive(node->right, value);
    }
    return node; // return the node we started with
}

void IntBST::insert(int value) {
    // Start the recursive insertion at the root (possibly nullptr)
    // The address of the old or new root node will come back
    root = insertRecursive(root, value);
}

// Find the minimum value in subtree rooted at 'node'
int findMin(Node* node) {
    if (node->left == nullptr) {
        return node->data; // Base case: smallest value found
    } else {
        // Recurse on left subtree and return its smallest value
        return findMin(node->left);
    }
}

int sizeRecursive(Node* node) {
    if (node == nullptr) {
        return 0; // Base case: empty subtree
    }
    int leftSize = sizeRecursive(node->left);
    int rightSize = sizeRecursive(node->right);
    return 1 + leftSize + rightSize;
}

int IntBST::size() {
    return sizeRecursive(root);
}

void clearRecursive(Node* node) {
    if (node == nullptr) {
        return; // Base case: nothing to delete
    }
    // Recurse on left and right subtrees
    clearRecursive(node->left);
    clearRecursive(node->right);
    // Now delete this node
    delete node;
}

void IntBST::clear() {
    clearRecursive(root); // Call helper on root
    root = nullptr;       // Tree is now empty
}

IntBST::~IntBST() {
    clear(); // Clear all nodes
}

Node* copyRecursive(Node* sourceNode) {
    if (sourceNode == nullptr) {
        return nullptr; // Base case: nothing to copy
    }
    // Create new node with same value
    Node* newNode = new Node(sourceNode->data);
    // Recursively copy left and right subtrees
    newNode->left = copyRecursive(sourceNode->left);
    newNode->right = copyRecursive(sourceNode->right);
    return newNode; // Return address of new node
}

IntBST::IntBST(const IntBST& other) {
    root = copyRecursive(other.root); // Deep copy of other's tree's nodes
}

IntBST& IntBST::operator=(const IntBST& other) {
    if (this != &other) {                 // Self-assignment check
        clear();                          // Clear current tree
        root = copyRecursive(other.root); // Deep copy of other's tree's nodes
    }
    return *this; // Return this object
}

Node* removeRecursive(Node* node, int value) {
    if (node == nullptr) {
        return nullptr; // value not found, nothing is there
    }
    if (value < node->data) {
        // Value is in left subtree
        node->left = removeRecursive(node->left, value);
    } else if (value > node->data) {
        // Value is in right subtree
        node->right = removeRecursive(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            // Case 1: No children
            delete node;
            return nullptr; // Position is now empty
        } else if (node->left == nullptr || node->right == nullptr) {
            // Case 2: One child
            Node* child;
            if (node->left != nullptr) {
                child = node->left; // Has left child
            } else {
                child = node->right; // Has right child
            }
            delete node;
            return child; // child replaces the node
        } else {
            // Case 3: Two children
            // Find the minimum value in the right subtree
            int minValue = findMin(node->right);
            node->data = minValue; // Replace value with min value
            // Remove the duplicate value from the right subtree
            node->right = removeRecursive(node->right, minValue);
        }
    }
    return node; // node remains unchanged
}

void IntBST::remove(int value) {
    root = removeRecursive(root, value); // Call helper on root
}

void printInOrderRecursive(Node* node) {
    if (node == nullptr) {
        return; // Base case: nothing to print
    }
    printInOrderRecursive(node->left);  // Print left subtree
    std::cout << node->data << " ";     // Print this node's data
    printInOrderRecursive(node->right); // Print right subtree
}

void IntBST::printInOrder() {
    printInOrderRecursive(root); // Start in-order printing at root
}