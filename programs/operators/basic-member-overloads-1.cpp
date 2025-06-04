// Rational class code here but hidden

Rational Rational::operator+(const Rational& other) const {
    int newNumerator =
        m_numerator * other.m_denominator + other.m_numerator * m_denominator;
    int newDenominator = m_denominator * other.m_denominator;
    Rational result(newNumerator, newDenominator);
    return result.simplify();
}

bool Rational::operator==(const Rational& other) const {
    return m_numerator * other.m_denominator
           == other.m_numerator * m_denominator;
}

int main() {
    Rational r1(1, 2); // Represents 1/2
    Rational r2(2, 3); // Represents 2/3

    Rational sum = r1 + r2;
    cout << "Sum: " << sum.toString() << endl;

    bool areEqual = r1 == r2;
    cout << "Are r1 and r2 equal? " << (areEqual ? "Yes" : "No") << endl;
}