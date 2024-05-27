#include "fraction.h"
#include <iostream>
#include <ostream>

using std::cout;
using std::endl;

int main() {
  Fraction fr1;
  Fraction fr2(2, 4);
  Fraction fr3(fr2);

  cout << "fr1: " << fr1 << endl;
  cout << "fr2: " << fr2 << endl;
  cout << "fr3: " << fr3 << endl;

  cout << endl;
  
  cout << "fr1 + fr2 = " << fr1+fr2 << endl;
  cout << "fr2 + fr3 = " << fr2+fr3 << endl;

  cout << endl;

  cout << "fr2 + 3 = " << double(fr2 + 3) << endl;
  cout << "fr2 - 1 = " << double(fr2 - 1) << endl;
  cout << "1/6 * 2 = " << Fraction(1,6) * 2 << endl;
  cout << "1/3 / 1/6 = " << double(Fraction(1,3) / Fraction(1,6)) << endl;

  cout << endl << endl;

  
  FractionEX frax1(1, 2, 3);
  FractionEX frax2(2, 2, 6);

  cout << "frax1 = " << frax1 << endl;
  cout << "frax2 = " << frax2 << endl;

  cout << endl;

  cout << "frax1 + frax2 = " << (double)(frax1 + frax2) << endl;
  cout << "frax2 - frax1 = " << frax2 - frax1 << endl;
  cout << "frax2 * 3 = " << frax2 * 3 << endl;
  cout << "2+1/2 / 1/2" << FractionEX(2, 1, 2) / FractionEX(0, Fraction(1, 2));

  return 0;
}
