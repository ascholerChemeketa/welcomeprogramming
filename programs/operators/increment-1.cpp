//Rational class code here but hidden

Rational& Rational::operator++() {
  m_numerator += m_denominator; // Increment by 1
  return *this; // Return this object
}

int main() {
  Rational r1(1, 2); // Represents 1/2

  cout << "r1: " << r1.toString() << endl;
  cout << "Incrementing r1..." << endl;
  ++r1;
  cout << "r1: " << r1.toString() << endl;
  cout << "r2 = ++r1..." << endl;
  Rational r2 = ++r1;
  cout << "r1: " << r1.toString() << endl;
  cout << "r2: " << r2.toString() << endl;
}