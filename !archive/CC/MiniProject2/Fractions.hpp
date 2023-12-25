// ================  DO NOT TOUCH THIS FILE =====================

#include <bits/stdc++.h>

template <typename T> class Fraction {
  public:
    Fraction(T, T);
    Fraction reduce();
    T get_numerator();
    T get_denominator();
    Fraction operator+(Fraction&);
    Fraction operator-(Fraction&);
    Fraction operator*(Fraction&);
    Fraction operator/(Fraction&);
    bool operator==(Fraction&);
    bool operator!=(Fraction&);
    bool operator<=(Fraction&);
    bool operator<(Fraction&);
    bool operator>=(Fraction&);
    bool operator>(Fraction&);
    void print();

  private:
    T numerator;
    T denominator;
    const char div_char = '/';
};

template <typename T>
T gcd(T,T);


