

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
  
      double a1 = getDoubled(n1);
      CHECK(a1 == doctest::Approx(4));
      double a2 = getDoubled(n2);
      CHECK(a2 == doctest::Approx(3.0));
  }