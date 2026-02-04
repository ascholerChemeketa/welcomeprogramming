#include <iostream>
using namespace std;

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

int main() {
    // Create three nodes
    ListNode* node1 = new ListNode(12);
    ListNode* node2 = new ListNode(6);
    ListNode* node3 = new ListNode(10);

    // Connect the nodes into a list: node1 -> node2 -> node3
    node1->next = node2;
    node2->next = node3;

    // Print the list
    cout << node1->data << ", ";
    cout << node1->next->data << ", ";
    cout << node1->next->next->data << endl;
}