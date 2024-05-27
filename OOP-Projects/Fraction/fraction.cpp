#include "fraction.h"
#include <stdexcept>

using std::logic_error;
using std::max;

/*
 * CONSTRUCTORS
 */

Fraction::Fraction() {};

Fraction::Fraction(const Fraction& frac) { 
  _numerator = frac._numerator;
  _denominator = frac._denominator;
}

Fraction::Fraction(const int num, const int denom) {
  _numerator = num;
  _denominator = denom;

  if (denom < 0) {
    _numerator = -_numerator;
    _denominator = -_denominator;
  } else if (denom == 0)
    throw logic_error("To not let the Universe collaps devision by 0 is forbidden");

  simplify();
}


/* 
 * Private functions 
 */
inline int HCD(int a, int b) {  // Highest Common Delimeter
  if (a == b) return a;
  int out = 1;
  for (int i = 2; i <= (max(a, b)/2 + 1); i++) {
    if (a%i == 0 && b%i == 0) out = i;
  }
  return out;
}
  
void Fraction::simplify() {
  int hcd = HCD(_numerator, _denominator);
  _numerator /= hcd;
  _denominator /= hcd;  
}

/*
 * Operator overloads
 */

Fraction Fraction::operator+ (const Fraction& frac) {
  int num = _numerator * frac._denominator + frac._numerator * _denominator;
  int den = _denominator * frac._denominator;
  return Fraction(num, den);
}

Fraction Fraction::operator+ (const int n) {
  int num = n * _denominator + _numerator;
  return Fraction(num, _denominator);
}


Fraction Fraction::operator- (const Fraction& frac) {
  int num = _numerator * frac._denominator - frac._numerator * _denominator;
  int den = _denominator * frac._denominator;
  return Fraction(num, den);
}

Fraction Fraction::operator- (const int n) {
  int num = _numerator - n * _denominator;
  return Fraction(num, _denominator);
}


Fraction Fraction::operator* (const Fraction& frac) {
  int num = _numerator * frac._numerator;
  int den = _denominator * frac._denominator;
  return Fraction(num, den);
}

Fraction Fraction::operator* (const int n) {
  int num = _numerator * n;
  return Fraction(num, _denominator);
}


Fraction::operator double() {
  return (double)_numerator/_denominator;
}


Fraction Fraction::operator/ (const Fraction& frac) {
  int num = _numerator * frac._denominator;
  int den = _denominator * frac._numerator;
  return Fraction(num, den);
}

Fraction Fraction::operator/ (const int n) {
  int den = _denominator * n;
  return Fraction(_numerator, den);
}


std::ostream& operator<<(std::ostream& cout, const Fraction& frac) {
  return cout << frac._numerator << '/' << frac._denominator;
}


/// ===========
///  CONSTRUCTORS
/// ===========
FractionEX::FractionEX() {};

FractionEX::FractionEX(const FractionEX& frac) {
  _numerator = frac._numerator;
  _denominator = frac._denominator;
  _quotient = frac._quotient; 
}

FractionEX::FractionEX(const int n, const int num, const int denom) : Fraction(num, denom) {
  _quotient = n;
  simplify();
}

FractionEX::FractionEX(const int n, const Fraction& frac) : Fraction(frac) {
  _quotient = n;
  simplify();
}

Fraction FractionEX::toFraction() const {
  return Fraction(_quotient*_denominator+_numerator, _denominator);
}

/// ==========
///  Private functions
/// ==========
void FractionEX::simplify() {
  Fraction::simplify();
  _quotient += _numerator / _denominator;
  _numerator %= _denominator;
}

/// ==========
///  Operator overloads
/// ==========
FractionEX FractionEX::operator+(const FractionEX& frac) {
  return FractionEX((*this).toFraction() + frac.toFraction());
}

FractionEX FractionEX::operator+(const int n) {
  return FractionEX((*this).toFraction() + n);
}


FractionEX FractionEX::operator-(const FractionEX& frac) {
  return FractionEX((*this).toFraction() - frac.toFraction());
}

FractionEX FractionEX::operator-(const int n) {
  return FractionEX((*this).toFraction() - n);
}


FractionEX FractionEX::operator*(const FractionEX& frac) {
  return FractionEX((*this).toFraction() * frac.toFraction());
}

FractionEX FractionEX::operator*(const int n) {
  return FractionEX((*this).toFraction() * n);
}


FractionEX FractionEX::operator/(const FractionEX& frac) {
  return FractionEX((*this).toFraction() / frac.toFraction());
}

FractionEX FractionEX::operator/(const int n) {
  return FractionEX((*this).toFraction() / n);
}


FractionEX::operator double() {
  return _quotient + Fraction(*this);
}

std::ostream& operator<<(std::ostream& cout, const FractionEX& frac) {
  return cout << frac._quotient << "+" << frac._numerator << '/' << frac._denominator;
}
