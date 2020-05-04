#include <iostream>
#include "Complex.h"

Complex::Complex(float re, float im)
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

void Complex::setReal(double r)
{
    real = r;
}

void Complex::setImaginar(double i)
{
    imaginar = i;
}

double getReal()
{
    return real;
}

double getImaginar()
{
    return imaginar;
}

Complex operator+(Complex a, Complex b)
{
    Complex sum;
    sum.setReal(a.real + b.real);
    sum.setImaginar(a.imaginar + b.imaginar);
    return sum;
}

Complex operator*(Complex a, Complex b)
{
    Complex prod;
    if (a.imaginar == 0) {
        prod.setReal(a.real * b.real);
        prod.setImaginar(a.real * b.imaginar);
    }
    else if (b.imaginar == 0) {
        prod.setReal(a.real * b.real);
        prod.setImaginar(b.real * a.imaginar);
    }
    else {
        prod.setReal(a.real * b.real - a.imaginar * b.imaginar);
        prod.setImaginar(a.real * b.imaginar + b.real * a.imaginar);
    }
    return prod;
}

Complex operator*(double a, Complex b)
{
    return Complex(b.real * a, b.imaginar * a);
}

bool operator==(const Complex& a, const Complex& b)
{
    return (a.real == b.real and a.imaginar == a.imaginar);
}

bool operator!=(const Complex& a, const Complex& b) 
{
    return !(a == b);
}
