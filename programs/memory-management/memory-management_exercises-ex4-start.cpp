#include <iostream>

using namespace std;

class NumberWrapper {
public:
    NumberWrapper(int num);
    void setNum(int value);
    int getNum() const;
    ~NumberWrapper();

    NumberWrapper(const NumberWrapper& other);
    NumberWrapper& operator=(const NumberWrapper& other);

private:
    int* m_myAddress; // Memory address of number we own
};

NumberWrapper::NumberWrapper(int num) {
    m_myAddress = new int(num);
}

void NumberWrapper::setNum(int value) {
    *m_myAddress = value;
}

int NumberWrapper::getNum() const {
    return *m_myAddress;
}

NumberWrapper::~NumberWrapper() {
    delete m_myAddress;
}
