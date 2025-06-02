#include <iostream>

using namespace std;

class Animal {
private:
    int m_numLegs;
public:
    Animal(int legs) {
        m_numLegs = legs;
    }
    
    int getNumLegs() const {
        return m_numLegs;
    }
};