#include <iostream>
#include "Complex.h"

Complex::Complex(int re, int im)
{
    real = re;
    imaginar = im;
}

Complex::Complex(const Complex& ob) = default;

Complex::~Complex() = default;

Complex& Complex::operator=(const Complex&) = default;

std::istream& operator>>(std::istream & in, Complex & nr)
{
    in >> nr.real >> nr.imaginar;
    return in;
}

std::ostream& operator<<(std::ostream & out, Complex & nr)
{
    out << nr.real << "+" << nr.imaginar << "i";
    return out;
}
