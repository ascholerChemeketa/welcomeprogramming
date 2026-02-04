#include <iostream>
#include <vector>

using namespace std;

class IntStack {
private:
    vector<int> elements; // Internal storage for stack elements
public:
    void push(int value) {
        elements.push_back(value);
    }

    int pop() {
        if (elements.empty()) {
            throw runtime_error("Stack is empty");
        }
        int value = elements.back();
        elements.pop_back();
        return value;
    }

    bool isEmpty() const {
        return elements.empty();
    }

    int peek() const {
        if (elements.empty()) {
            throw runtime_error("Stack is empty");
        }
        return elements.back();
    }
};

int main() {
    IntStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl; // Should print 30

    while (!stack.isEmpty()) {
        cout << "Popped element: " << stack.pop() << endl;
    }
} 