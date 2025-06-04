#include <iostream>

using namespace std;

class Rational {
public:
  // all public for this simple demo
  int m_numerator = 0;
  int m_denominator = 1;
  // is this object a copy of another one?
  bool m_isCopy = false;

  Rational(int n, int d) {
    m_numerator = n;
    m_denominator = d;
  }
  
  Rational& operator=(const Rational& other) {
      // copy numerator and denominator
      m_numerator = other.m_numerator;
      m_denominator = other.m_denominator;
      // set m_isCopy to true
      m_isCopy = true;
      return *this; // return current object
  }
};

int main() {
  Rational r1(2, 3);
  Rational r2(1, 1);
  
  // Copy r1 into r2 using
  r2 = r1; //r2.operator=(r1)
  cout << r2.m_isCopy;
}
