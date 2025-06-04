#include <iostream>
using namespace std;

class EvenNumber {
public:
    explicit EvenNumber(int n) {
        m_value = (n % 2 == 0) ? n : n - 1; // must be even
    }
    
    bool operator==(const EvenNumber& other) const;
    
    int getValue() const {
        return m_value;
    }
    
private:
    int m_value;
};
