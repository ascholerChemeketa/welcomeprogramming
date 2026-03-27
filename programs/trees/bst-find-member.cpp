// Non-recursive member function that starts the recursive search
bool IntBST::find(int target) {
    // Start the recursive search at the root
    return findRecursive(root, target);
}
