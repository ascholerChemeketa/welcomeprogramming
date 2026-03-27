#include <iostream>

import IntBST;

using namespace std;

int main() {
    IntBST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    cout << "After inserting 50, 30, 70:" << endl;
    tree.printInOrder();
    cout << endl;
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    cout << "After inserting 20, 40, 60, 80:" << endl;
    tree.printInOrder();
    cout << endl;

    cout << "Size of the tree: " << tree.size() << endl;

    int targets[] = {25, 40, 55, 70};
    for (int target : targets) {
        if (tree.find(target)) {
            cout << target << " found in the tree." << endl;
        } else {
            cout << target << " not found in the tree." << endl;
        }
    }

    tree.remove(20);
    cout << "After removing 20:" << endl;
    tree.printInOrder();
    cout << endl;
    
    tree.remove(50);
    cout << "After removing 50:" << endl;
    tree.printInOrder();
    cout << endl;

    IntBST copyTree = tree; // Test copy constructor
    copyTree.insert(90);
    cout << "Original tree after copying and modifying the copy:" << endl;
    tree.printInOrder();
    cout << endl;
    cout << "Copied tree after inserting 90:" << endl;
    copyTree.printInOrder();
    cout << endl;
}