module;

#include <format>
#include <string>

export module GeometricObject;

using namespace std;

export class GeometricObject {
protected:
    string m_color;
    
public:
    // Constructor
    GeometricObject(string color);
    
    // getArea is an abstract function
    //   we have no way to do it at the base class level
    virtual double getArea() const = 0;
    
    // getColor is a regular virtual function
    //   it does not necessarily need to be virtual, it is unlikely
    //   to be overridden in derived classes
    virtual string getColor() const;
    
    // toString is a regular virtual function
    //   we can do the job here, but derived classes will likely want to override
    //   it to provide more specific information
    virtual string toString() const;
};

GeometricObject::GeometricObject(string color)
{
    this->m_color = color;
}

// getArea is abstract... nothing to list!

// note we do not use virtual outside the class
string GeometricObject::getColor() const
{
    return m_color;
}

string GeometricObject::toString() const
{
    return format("A {} object.", m_color);
}