module;

#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

export module ArrayBasedQueue;

using namespace std;

const int QUEUE_INIT_SIZE = 8;

export template<typename T>
class Queue {
    // Normally would be private, public to enable intrusive unit tests
public:
    T* list;       // array to hold the list elements
    int arraySize; // capacity of array used for storage

    int start; // index of the front of the queue
    int end;   // index of next available location at back

    // Helper function to add additional space
    void grow();

public:
    void enqueue(const T& value);
    T dequeue();
    bool empty() const;
    bool full() const;

    Queue();
    ~Queue();

    // Disable copy ctor and assignment to avoid accidental use
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    string toString();
};

template<typename T>
string Queue<T>::toString() {
    stringstream s;
    s << "Start: " << start << " End: " << end << " arraySize: " << arraySize
      << endl;

    int length = end - start;
    bool wrapped = false; // does queue wrap around back of array?
    if (length < 0)
        wrapped = true;

    for (int i = 0; i < arraySize; i++) {
        if ((wrapped && (i < end || i >= start))
            || (!wrapped && (i < end && i >= start)))
            s << setw(4) << list[i];
        else
            s << setw(4) << "_";
    }
    return s.str();
}

template<typename T>
Queue<T>::Queue() {
    arraySize = QUEUE_INIT_SIZE;
    start = 0;
    end = 0;
    list = new T[arraySize];
}

template<typename T>
Queue<T>::~Queue() {
    delete[] list;
}

//-----------Other functions to be built------------------
