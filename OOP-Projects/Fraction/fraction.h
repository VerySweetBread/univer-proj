#include <iostream>
#include <stdexcept>

class Fraction {
protected:
  int _numerator = 0;
  int _denominator = 1;
  void simplify();

public:
  /// =========
  ///  CONTRUCTORS
  /// ==========
  Fraction();
  Fraction(const Fraction& frac);
  Fraction(const int num, const int denom);
  Fraction(const double n)                 { throw std::logic_error("Not implemented"); }

  /// =========
  ///  Operator overloads
  /// ==========
  Fraction operator+ (const Fraction& frac);
  Fraction operator+ (const int n);
  Fraction operator+ (const double n)       { throw std::logic_error("Not implemented"); }
  
  Fraction operator- (const Fraction& frac);
  Fraction operator- (const int n);
  Fraction operator- (const double n)       { throw std::logic_error("Not implemented"); }
  
  Fraction operator* (const Fraction& frac);
  Fraction operator* (const int n);
  Fraction operator* (const double n)       { throw std::logic_error("Not implemented"); }
  
  Fraction operator/ (const Fraction& frac);
  Fraction operator/ (const int n);
  Fraction operator/ (const double n)       { throw std::logic_error("Not implemented"); }

  operator double();

  friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};

class FractionEX : public Fraction {
protected:
  // int _numerator = 0;
  // int _denominator = 1;
  int _quotient = 0;
  
  void simplify();

public:
  /// =========
  ///  CONTRUCTORS
  /// ==========
  FractionEX();
  FractionEX(const FractionEX& frac);
  FractionEX(const int n, const int num, const int denom);
  FractionEX(const int n, const Fraction& frac);
  // FractionEX(const double n)                 { throw std::logic_error("Not implemented"); }

  Fraction toFraction() const;

  /// =========
  ///  Operator overloads
  /// ==========
  FractionEX operator+ (const FractionEX& frac);
  FractionEX operator+ (const int n);
  
  FractionEX operator- (const FractionEX& frac);
  FractionEX operator- (const int n);
  
  FractionEX operator* (const FractionEX& frac);
  FractionEX operator* (const int n);
  
  FractionEX operator/ (const FractionEX& frac);
  FractionEX operator/ (const int n);
  

  operator double();
  
  friend std::ostream& operator<<(std::ostream& os, const FractionEX& frac);
};
