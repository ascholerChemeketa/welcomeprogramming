

class Int : public Number {
private:
  int m_value;

public:
  Int(int i) {
    m_value = i;
  }
  double getValue() const {
    return m_value;
  }
};

class Double : public Number {
private:
  double m_value;

public:
  Double(double d) {
    m_value = d;
  }
  double getValue() const {
    return m_value;
  }
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Test Numbers") {
    Int n1(2);
    Double n2(1.5);

    Number* temp = &n1; // point at the Int
    double n = temp->getValue(); // get the value as an int
    CHECK(n == doctest::Approx(2));
    cout << temp->getValue() << endl;

    temp = &n2; // point at the Double
    double d = temp->getValue(); // get the value as an int
    CHECK(d == doctest::Approx(1.5));
}