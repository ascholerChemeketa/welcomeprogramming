template <typename T>
class ArrayList {
private:
    T* m_arr;            // pointer to the array of type T
    int m_capacity;      // maximum number of elements
    int m_size;          // current number of elements

public:
    // Construct an empty ArrayList
    ArrayList();

    // Rule of Three
    // Copy another ArrayList of type T
    ArrayList(const ArrayList<T>& otherList);
    // Assign from another ArrayList of type T
    ArrayList<T>& operator=(const ArrayList<T>& other);
    // Destructor to free memory
    ~ArrayList();

    // Insert/remove item at end of list
    void insertEnd(const T& newItem);
    void removeEnd();

    // Access item at given location
    T get(int location) const;
    // Modify item at given location
    void set(int location, const T& newValue);

    // Ask how many items are in the list
    int size() const;

    // more to come...
};