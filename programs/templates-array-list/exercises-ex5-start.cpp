#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ItemCounter {
public:
    ItemCounter(T item);
    void increment();
    T getItem() const;
    int getCount() const;
private:
    T m_item;
    int m_count;
};
