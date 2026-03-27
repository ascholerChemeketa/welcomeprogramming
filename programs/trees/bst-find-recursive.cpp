bool findRecursive(Node* node, int target) {
    if (node == nullptr) {
        return false;  // Base case: target not found
    }
    if (node->data == target) {
        return true;   // Base case: target found
    }
    else if (target < node->data) {
        return findRecursive(node->left, target);  // Search left subtree
    }
    else {
        return findRecursive(node->right, target); // Search right subtree
    }
}