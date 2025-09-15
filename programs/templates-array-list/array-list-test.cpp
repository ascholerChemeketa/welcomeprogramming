#include <iostream>
import ArrayList;
using namespace std;

template<typename T>
void ArrayList<T>::insertEnd(const T& newItem) {
    if (m_size == m_capacity) {
        grow();
    }
    m_arr[m_size] = newItem;
    m_size++;
}


int main() {
    ArrayList<int> intList;
    intList.insertEnd(10);
    intList.insertEnd(20);
    intList.insertEnd(30);

    cout << "ArrayList contents: " << endl;
    for(int i = 0; i < intList.size(); ++i) {
        cout << intList.get(i) << " ";
    }
    cout << endl;
}