module;

#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stdexcept>

export module StringHashTable;

using namespace std;

export class StringHashTable {
//Normally private, made public to allow intrusive unit tests
public:
    int m_capacity;              //size of buckets array
    int m_size;                  //items stored
    std::string* m_buckets;
    const double MAX_LOAD = 0.7;

    //value used to indicate a cell is empty - cannot be stored in set
    const std::string EMPTY = "";
    //value used to indicate a cell is empty but once had a value
    const std::string TOMBSTONE = "#";

    void grow();

    //Determine bucket given items should be in
    unsigned int getBucket(const std::string& key) const;

public:
    StringHashTable(int numBuckets = 8);

    bool contains(const std::string& key) const;
    void insert(const std::string& key);
    void remove(const std::string& key);
    int size() const;

    string toString() const;

    //Memory management
    ~StringHashTable();
    //Copy ctor and assignment operator disabled
    StringHashTable(const StringHashTable& other) = delete;
    StringHashTable& operator=(const StringHashTable& other) = delete;
};


StringHashTable::StringHashTable(int numBuckets)
{
    m_size = 0;
    m_capacity = numBuckets;
    m_buckets = new string[numBuckets];

    //We can count on strings being initialized to "" which is our EMPTY value
    //If some other value was EMPTY we would need:
    //    for(int i = 0; i < m_capacity; i++)
    //        m_buckets[i] = EMPTY;
}

StringHashTable::~StringHashTable()
{
    delete [] m_buckets;
}

string StringHashTable::toString() const
{
    string result = "Buckets[ ";
    for(int i = 0; i < m_capacity; i++) {
        if(m_buckets[i] == EMPTY)
            result += "_ ";
        else if(m_buckets[i] == TOMBSTONE)
            result += "# ";
        else
            result += m_buckets[i] + " ";
    }
    result += "]";
    return result;
}

int StringHashTable::size() const {
    return m_size;
}


unsigned int StringHashTable::getBucket(const std::string& key) const {
    std::hash<string> hasher;
    //std::hash returns size_t - we will store in unsigned int
    unsigned int hashValue = static_cast<unsigned int>(hasher(key));

    //return that mapped onto table
    return hashValue % m_capacity;
}

// Other functions to be implemented