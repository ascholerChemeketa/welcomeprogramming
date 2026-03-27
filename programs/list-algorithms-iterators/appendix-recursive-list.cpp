module;

#include <string>
#include <iostream>

export module SimpleLinkedList;

using namespace std;

export struct ListNode {
    ListNode(int value);
    ~ListNode();

    ListNode* next = nullptr;
    int data = 0;

    //Maintain a count of active nodes for testing
    // Not normally a part of the struct.
    // You should NOT modify or even use this value in your code.
    static int nodeCount;
};

int ListNode::nodeCount = 0;

ListNode::ListNode(int value) {
    data = value;
    nodeCount++;
}

ListNode::~ListNode() {
    nodeCount--;
}


export class SimpleLinkedList
{
public:
    ~SimpleLinkedList();

    //Provided:
    void insertStart(int value);
    void removeLast();
    int retrieveAt(int index);
    int getTotal();
    std::string toString();

    //To implement:
    std::string reverseToString();
    int getMaxValue();

private:
    ListNode* head = nullptr;
};


void SimpleLinkedList::insertStart(int value) {
    ListNode* newNode = new ListNode(value);

    newNode->next = head;
    head = newNode;
}


//Assumes there is at least one node to work with
string recursiveToString(ListNode* current) {
    if(current->next == nullptr)
        return to_string(current->data);

    string rest = recursiveToString(current->next);
    string result = to_string(current->data) + " " + rest;

    return result;
}

string SimpleLinkedList::toString() {
    if(head == nullptr)
        return "";
    return recursiveToString(head);
}

//---------------------------------------------

int recursiveGetTotal(ListNode* current) {
    if(current == nullptr) {
        cout << "At nullptr, returning 0" << endl;
        return 0;
    }
    else {
        cout << "At " << current->data << " node, recursing to next node" << endl;
        int everyoneElse = recursiveGetTotal(current->next);
        int total = current->data + everyoneElse;
        cout << "Returning from " << current->data << " node a total of " << total << endl;
        return total;
    }
}

int SimpleLinkedList::getTotal()
{
    return recursiveGetTotal(head);
}

//---------------------------------------------

int recursiveRetrieveAt(ListNode* current, int stepsLeft) {
    // Missing : if current == nullptr throw exception

    if(stepsLeft == 0)
        return current->data;
    else {
        return recursiveRetrieveAt(current->next, stepsLeft - 1);
    }
}

int SimpleLinkedList::retrieveAt(int index) {
    return recursiveRetrieveAt(head, index);
}


//---------------------------------------------

ListNode* recursiveRemoveLast(ListNode* current) {
    if(current->next == nullptr) {
        cout << "At last node with value " << current->data << endl;
        delete current;
        cout << "Deleted last node, returning nullptr" << endl;
        return nullptr;
    }
    else {
        cout << "At node with value " << current->data << " address of " << current << ", recursing to next node" << endl;
        ListNode* newNext = recursiveRemoveLast(current->next);
        cout << "Back at node with value " << current->data << ", setting its next pointer to " << newNext << endl;
        current->next = newNext;
        cout << "Returning address " << current << endl;
        return current;
    }
}

void SimpleLinkedList::removeLast() {
    if(head != nullptr) {
        cout << "Starting removeLast operation on head node at " << head << endl;
        ListNode* newHead = recursiveRemoveLast(head->next);
        cout << "Done with recursion, update head to " << newHead << endl;
        head = newHead;
    }
}

//---------------------------------------------

void recursiveDelete(ListNode* current) {
    if(current == nullptr)
      return;
    recursiveDelete(current->next);
    delete current;
}


SimpleLinkedList::~SimpleLinkedList()
{
    recursiveDelete(head);
    head = nullptr;
}
