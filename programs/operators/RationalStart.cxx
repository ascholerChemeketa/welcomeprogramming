#include <format>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>

using namespace std;

class Rational {
private:
    int m_numerator;
    int m_denominator;

public:
    Rational(int numerator, int denominator);

    int getNumerator() const;
    int getDenominator() const;
    double doubleValue() const;
    string toString() const;

    // Make a new Rational object that is the simplified version of this one
    Rational simplify() const;

    // Some functions we will build later...
    // Non-operator functions
    Rational add(const Rational& other) const;
    bool equals(const Rational& other) const;

    // Operators versions of those functions
    Rational operator+(const Rational& other) const;
    bool operator==(const Rational& other) const;

    // Other operators
    Rational& operator++();   // Prefix increment
    Rational operator++(int); // Postfix increment
    Rational& operator--();   // Prefix decrement
    Rational operator--(int); // Postfix decrement
};

Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    m_numerator = numerator;
    m_denominator = denominator;
}

int Rational::getNumerator() const {
    return m_numerator;
}

int Rational::getDenominator() const {
    return m_denominator;
}

double Rational::doubleValue() const {
    return static_cast<double>(m_numerator) / m_denominator;
}

string Rational::toString() const {
    string stringRep = format("{}/{}", m_numerator, m_denominator);
    return stringRep;
}

Rational Rational::simplify() const {
    int divisor = std::gcd(abs(m_numerator), abs(m_denominator));
    int newNumerator = m_numerator / divisor;
    int newDenominator = m_denominator / divisor;
    // - sign should only be in the numerator
    if (newDenominator < 0) {
        newNumerator = -newNumerator;
        newDenominator = -newDenominator;
    }
    return Rational(newNumerator, newDenominator);
}