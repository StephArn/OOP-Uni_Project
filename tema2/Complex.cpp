#include <iostream>
#include "Complex.h"

using namespace std;

template<class T>

Complex<T>::Complex(T re, T im)
{
    real = re;
    imaginar = im;
}

template<class T>

istream& operator>>(istream& in, Complex<T>& nr)
{
    in >> nr.real >> nr.imaginar;
    return in;
}

template<class T>

ostream& operator<<(ostream& out, Complex<T>& nr)
{
    out << nr.real << "+" << nr.imaginar << "i";
    return out;
}


template<class T>
void Complex<T>::setReal(T r)
{
    real = r;
}
template<class T>

void Complex<T>::setImaginar(T i)
{
    imaginar = i;
}

template<class T>

float Complex<T>::getReal()
{
    return real;
}

template<class T>

float Complex<T>::getImaginar()
{
    return imaginar;
}

template<class T>

Complex<T> operator+(Complex<T> a, Complex<T> b)
{
    Complex<T> sum;
    sum.setReal(a.real + b.real);
    sum.setImaginar(a.imaginar + b.imaginar);
    return sum;
}

template<class T>

Complex<T> operator*(T a, Complex<T> b)
{
    Complex<T> prod;
    prod.setReal(b.real * a);
    prod.setImaginar(b.imaginar * a);
    return prod;
}

template<class T>

Complex<T> operator*(Complex<T> a, Complex<T> b)
{
    Complex<T> prod;
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

template<class T>

bool operator==(const Complex<T>& a, const Complex<T>& b)
{
    return (a.real == b.real and a.imaginar == a.imaginar);
}

template<class T>

bool operator!=(const Complex<T>& a, const Complex<T>& b)
{
    return !(a == b);
}

template class Complex<float>;
template istream& operator>><float>(istream&, Complex<float>&);
template ostream& operator<< <float>(ostream&, Complex<float>&);
template Complex<float> operator+<float>(Complex<float>, Complex<float>);
template Complex<float> operator*<float>(float, Complex<float>);
template Complex<float> operator*<float>(Complex<float>, Complex<float>);
template bool operator==<float>(const Complex<float>&, const Complex<float>&);
template bool operator!=<float>(const Complex<float>&, const Complex<float>&);

template class Complex<int>;
template istream& operator>><int>(istream&, Complex<int>&);
template ostream& operator<< <int>(ostream&, Complex<int>&);
template Complex<int> operator+<int>(Complex<int>, Complex<int>);
template Complex<int> operator*<int>(int, Complex<int>);
template Complex<int> operator*<int>(Complex<int>, Complex<int>);
template bool operator==<int>(const Complex<int>&, const Complex<int>&);
template bool operator!= <int>(const Complex<int>&, const Complex<int>&);

