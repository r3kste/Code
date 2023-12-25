#include "Fractions.hpp"
#include <bits/stdc++.h>

template <typename T>
T gcd (T a, T b)
{
    return b ? gcd<T> (b, a % b) : a;
}

//===================== DO NOT TOUCH THE STUFF ABOVE ==========

// print() implementation:
// it should print the fraction in the following order in its lowest form
// 1/2
// terminated by a newline, no spaces or anything else

//=========== YOUR CODE HERE ==============

template <typename T>
inline Fraction<T>::Fraction (T n, T d) : numerator (n), denominator (d)
{
    this->numerator = n;
    this->denominator = d;
}