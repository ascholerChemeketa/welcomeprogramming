#include <iostream>

using namespace std;

class Animal {
public:
    bool isOrganism() const {
        return true;
    }
    
    string getTypeString() const {
        return "Animal";
    }
};
