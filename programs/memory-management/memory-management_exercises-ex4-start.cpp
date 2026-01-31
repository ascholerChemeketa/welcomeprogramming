#include <iostream>
using namespace std;

class NumberWrapper {
public:
    NumberWrapper(int num1, int num2);
    void setNum(int position, int value);
    int getNumOne() const;
    int getNumTwo() const;
    ~NumberWrapper();

    NumberWrapper(const NumberWrapper& other);
    NumberWrapper& operator=(const NumberWrapper& other);

private:
    int* m_myAddress; // Memory address of array
};

NumberWrapper::NumberWrapper(int num1, int num2) {
    m_myAddress = new int[2];
    m_myAddress[0] = num1;
    m_myAddress[1] = num2;
}

void NumberWrapper::setNum(int position, int value) {
    m_myAddress[position] = value;
}

int NumberWrapper::getNumOne() const {
    return m_myAddress[0];
}

int NumberWrapper::getNumTwo() const {
    return m_myAddress[1];
}

NumberWrapper::~NumberWrapper() {
    delete[] m_myAddress;
}
