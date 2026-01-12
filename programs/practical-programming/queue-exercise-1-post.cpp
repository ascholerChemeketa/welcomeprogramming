

int main() {
    queue<int> intQueue1;
    intQueue1.push(1);
    intQueue1.push(2);
    intQueue1.push(3);
    intQueue1.push(4);
    emptyQueue(intQueue1);

    intQueue1.push(10);
    intQueue1.push(11);
    intQueue1.push(12);
    emptyQueue(intQueue1);
}