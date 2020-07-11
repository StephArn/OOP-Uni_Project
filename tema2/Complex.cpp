#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex(float re, float im)
{
    real = re;
    imaginar = im;
}

istream& operator>>(istream & in, Complex & nr)
{
    in >> nr.real >> nr.imaginar;
    return in;
}

ostream& operator<<(ostream & out, Complex & nr)
{
    out << nr.real << "+" << nr.imaginar << "i";
    return out;
}

void Complex::setReal(float r)
{
    real = r;
}

void Complex::setImaginar(float i)
{
    imaginar = i;
}

float Complex::getReal()
{
    return real;
}

float Complex::getImaginar()
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

Complex operator*(int a, Complex b)
{
    return Complex(b.real * a, b.imaginar * a);
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

bool operator==(const Complex& a, const Complex& b)
{
    return (a.real == b.real and a.imaginar == a.imaginar);
}

bool operator!=(const Complex& a, const Complex& b) 
{
    return !(a == b);
}
