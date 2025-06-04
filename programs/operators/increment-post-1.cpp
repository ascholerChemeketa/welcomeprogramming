//Rational class code here but hidden

// int param indicates post-increment
Rational Rational::operator++(int) {
  // Create a copy of the object before incrementing
  Rational temp = *this;
  // Increment the current object
  m_numerator += m_denominator;
  // Return the copy of the object that has the old value
  return temp;
}

int main() {
  Rational r1(1, 2); // Represents 1/2

  cout << "r1: " << r1.toString() << endl;
  cout << "Incrementing r1..." << endl;
  r1++;
  cout << "r1: " << r1.toString() << endl;
  cout << "r2 = r1++..." << endl;
  Rational r2 = r1++;
  cout << "r1: " << r1.toString() << endl;
  cout << "r2: " << r2.toString() << endl;
}